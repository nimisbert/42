$fn = 6;

claustra_x = 1;
claustra_y = 0.05;
claustra_z = 1.67;

framing(claustra_x,claustra_y,claustra_z);
difference()
{
    beams(claustra_x, claustra_y, claustra_z, 5);
    
translate([claustra_x*0.3, claustra_y, claustra_z*0.3])
    rotate([90, 0, 0])
        hexagon(claustra_y, claustra_y*2, claustra_y);

translate([claustra_x*0.75, claustra_y, claustra_z*0.55])
    rotate([90, 0, 0])
        hexagon(claustra_y, claustra_y*2, claustra_y);

translate([claustra_x*0.3, claustra_y, claustra_z*0.75])
    rotate([90, 0, 0])
        hexagon(claustra_y, claustra_y*2, claustra_y);
}


translate([claustra_x*0.3, claustra_y, claustra_z*0.3])
    rotate([90, 0, 0])
        beehive(claustra_y, claustra_y*2, claustra_y);

translate([claustra_x*0.75, claustra_y, claustra_z*0.55])
    rotate([90, 0, 0])
        beehive(claustra_y, claustra_y*2, claustra_y);

translate([claustra_x*0.3, claustra_y, claustra_z*0.75])
    rotate([90, 0, 0])
        beehive(claustra_y, claustra_y*2, claustra_y);

module beams(x, y, h, n)
{
    for(i = [0: x/n: x])
    {
        translate([i, 0, 0])
            cube([y,y,h]);
    }
}

module framing(l, L, h)
{
    cube([L,L,h]);
    cube([l,L,L]);
    translate([l, 0, 0])
        cube([L,L,h]);
    translate([0, 0, h])
        cube([l+L,L,L]);
}

module vgrid(l, L, h)
{
    N = 10;
    step = l/N;
    for(i=[0: l/N :l])
    {
        translate([i*step, L, h])
            cube([1, 1, 1]);
    }
}

module hexagon(w, r, h)
{
    hull()
    {
        translate([w/2-r,0,0])
            cylinder(r=r, h=h);
        rotate([0,0,60])
            translate([w/2-r,0,0])
                cylinder(r=r, h=h);
        rotate([0,0,120])
            translate([w/2-r,0,0])
                cylinder(r=r, h=h);
        rotate([0,0,180])
            translate([w/2-r,0,0])
                cylinder(r=r, h=h);
        rotate([0,0,240])
            translate([w/2-r,0,0])
                cylinder(r=r, h=h);
        rotate([0,0,300])
            translate([w/2-r,0,0])
                cylinder(r=r, h=h);
    }
}

module beehive(w, r, h)
{
    difference(){
        hexagon(w, r, h);
        hexagon(w, r-r/10, h+1);
    }
}