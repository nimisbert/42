#include <stdio.h>
#include <stdbool.h>
#include <complex.h>

typedef struct CKT_COMPONENT {
    double R, L, C, w;
    double complex Z;
    bool isR, isL, isC;
} ckt_component_t;

ckt_component_t ckt_set_resistor         ( double R );
ckt_component_t ckt_set_inductor         ( double L );
ckt_component_t ckt_set_capacitor        ( double C ); 
double complex  ckt_cmp_impedance        ( ckt_component_t *this, double w );

void            ckt_print_component      ( ckt_component_t this );

int main(void)
{
// +--rs--+--LS--+
// |      |      |
// V      CP     RLoad
// |      |      |
// +-gnd--+------+
    ckt_component_t RLoad = ckt_set_resistor( 50.0 );
    ckt_component_t LS    = ckt_set_inductor( 32.8e-6 );
    ckt_component_t CP    = ckt_set_capacitor( 169e-12 );
    (void)ckt_cmp_impedance( &RLoad, 1 );
    (void)ckt_print_component( RLoad );
    (void)ckt_print_component( LS );
    (void)ckt_print_component( CP );
    return 0;
}

ckt_component_t ckt_set_resistor( double R )
{
    ckt_component_t this = { R, 0, 0, 0, 0, true, false , false };
    return this;
}

ckt_component_t ckt_set_inductor( double L )
{
    ckt_component_t this = { 0, L, 0, 0, 0, false, true, false };
    return this;
}

ckt_component_t ckt_set_capacitor( double C )
{
    ckt_component_t this = { 0, 0, C, 0, 0, false, false, true };
    return this;
}

ckt_component_t ckt_cmp_impedance( ckt_component_t *this, double w )
{
    this->w = w;
    if( this->isR ) {
        this->Z = this->R;
    }
    return this->Z;
}

void ckt_print_component( ckt_component_t this )
{
    if( this.isR ) {
        printf("R = %e Ohm\r\n", this.R);
    } else if( this.isL ) {
        printf("L = %e Henri\r\n", this.L);
    } else if( this.isC ) {
        printf("C = %e Farad\r\n", this.C);
    }
    printf("Z(w) = %e+j%e at %e rad/s\r\n", creal(this.Z), cimag(this.Z), this.w);
    return;
}