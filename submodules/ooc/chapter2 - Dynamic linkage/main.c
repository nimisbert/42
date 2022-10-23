#include <stdio.h>

#include <new.h>
#include <myString.h>


int main(void)
{
    void *a = new(String, "a");
    void *b = new(String, "b");
    void *aa= clone(a);


    printf("sizeOf(a) == %u\n", sizeOf(a));


    if(differ(a, b))
        puts("ok"); 
    if(differ(a,aa))
        puts("differ?");
    if(a==aa)
        puts("clone?");

    delete(a),delete(aa),delete(b);
    return 0;
}
