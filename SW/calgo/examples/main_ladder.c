#include <stdio.h>
#include <stdbool.h>
#include <complex.h>
#include <math.h>

typedef struct CKT_COMPONENT {
    double R, L, C, w;
    double complex z, v, i;
    bool isR, isL, isC;
} ckt_component_t;

ckt_component_t ckt_set_resistor         ( double R );
ckt_component_t ckt_set_inductor         ( double L );
ckt_component_t ckt_set_capacitor        ( double C ); 
double complex  ckt_cmp_impedance        ( ckt_component_t *this, double w );

void            ckt_print_component      ( ckt_component_t this );

void   ckt_ladder_init          ( ckt_component_t *down, double RLoad, double w );
void   ckt_ladder_fold_parallel ( const ckt_component_t *up, ckt_component_t *down );
void   ckt_ladder_fold_series   ( const ckt_component_t *up, ckt_component_t *down );
double ckt_ladder_end           ( ckt_component_t *down, double RSource );

int main(void)
{
    ckt_component_t LS = ckt_set_inductor( 23.1e-6 );
    ckt_component_t CP = ckt_set_capacitor( 463e-12 );
    for( double w = .5e6; w < 3e6; w+=5e4 ) {
        ckt_component_t CKT;
        (void)ckt_ladder_init( &CKT, 50.0, w );
        (void)ckt_ladder_fold_series( &LS, &CKT );
        (void)ckt_ladder_fold_parallel( &CP, &CKT );
        double P = ckt_ladder_end( &CKT, 1e3 );
        printf("P(%e) = %e dB\r\n",w,(10/log(10)) * log(P));
    }
    return 0;
}

ckt_component_t ckt_set_resistor( double R )
{
    ckt_component_t this = { R, 0, 0, 0, 0, 0, 0, true, false , false };
    return this;
}

ckt_component_t ckt_set_inductor( double L )
{
    ckt_component_t this = { 0, L, 0, 0, 0, 0, 0, false, true, false };
    return this;
}

ckt_component_t ckt_set_capacitor( double C )
{
    ckt_component_t this = { 0, 0, C, 0, 0, 0, 0, false, false, true };
    return this;
}

double complex ckt_cmp_impedance( ckt_component_t *this, double w )
{
    this->w = w;
    if( this->isR ) {
        this->z = this->R;
    }
    return this->z;
}

void ckt_ladder_init( ckt_component_t *down, double RLoad, double w )
{
    down->isR = down->isL = down->isC = false;
    down->z = 0;
    down->R = RLoad;
    down->w = w;
    down->i = 1+I*0;
    down->v = RLoad*(1+I*0);
    return;
}

void ckt_ladder_fold_parallel( const ckt_component_t *up, ckt_component_t *down )
{
    if( up==NULL || down==NULL ) {
        return;
    }
    down->v = down->v;
    if( up->isR ) {
        down->i = down->i + down->v/up->R;
    } else if ( up->isL ) {
        down->i = down->i + (down->v/( I * down->w * up->L ));
    } else if ( up->isC ) { 
        down->i = down->i + I * down->v * down->w * up->C;
    }
}

void ckt_ladder_fold_series( const ckt_component_t *up, ckt_component_t *down )
{
    if( up==NULL || down==NULL ) {
        return;
    }
    down->i = down->i;
    if( up->isR ) {
        down->v = down->v + down->i * up->R;
    } else if( up->isL ) {
        down->v = down->v + down->i * I * down->w * up->L;
    } else if( up->isC ) {
        down->v = down->v + (down->i / (I * down->w * up->C));
    }
    return;
}

double ckt_ladder_end( ckt_component_t *down, double RSource )
{
    down->z = down->v / down->i;
    down->v = down->v + down->i * RSource;
 //   frac=Rload./((abs(V).^2)/(4.*Rsource));
    return down->R / (pow(cabs(down->v), 2)) / (4*RSource);    
}

void ckt_print_component( ckt_component_t this )
{
    printf("----------------------------\r\n");
    if( this.isR ) {
        printf("R = %e Ohm\r\n", this.R);
    } else if( this.isL ) {
        printf("L = %e Henri\r\n", this.L);
    } else if( this.isC ) {
        printf("C = %e Farad\r\n", this.C);
    } else {
        printf("v(w) = %e+j%e Volts\r\n", creal(this.v), cimag(this.v));
        printf("i(w) = %e+j%e Amps\r\n", creal(this.i), cimag(this.i));
    }
    printf("Z(w) = %e+j%e at %e rad/s\r\n", creal(this.z), cimag(this.z), this.w);
    return;
}