#include "arquivo.h"

#define W 800
#define H 600
#define A 480000
#define ITERATIONS 1


float VectorSize(int,int);

void InitialLayout(Vertice*, int l);

void ApllyForces(Vertice*, int, UINT**);

int AtrForce(int, int);

int RepForce(int, int);


//area := W * L; { W and L are the width and length of the frame }
//G := (V, E); { the vertices are assigned random initial positions }
/*k :=
f u n c t i o n f a (z) := begin return x 2 /k e n d ;
f u n c t i o n f r(z) := begin return k 2 /z e n d ;
for i := 1 to iterations do begin
{ calculate repulsive forces}
for v in V do begin
{ each vertex has two vectors: .pos and .disp }
v.disp := 0;
for u in V d o
if (u # v) then begin
{ ∆ is short hand for the difference}
{ vector between the positions of the two vertices )
∆ := v.pos - u.pos;
v.disp := v.disp + ( ∆ /| ∆ |) * fr (| ∆ |)
end
end
{ calculate attractive forces }
for e in E do begin
{ each edge is an ordered pair of vertices .v and .u }
∆ := e.v.pos – e.u.pos
e.v.disp := e.v.disp – ( ∆/| ∆ |) * fa (| ∆ |);
e.u. disp := e.u.disp + ( ∆ /| ∆ |) * fa (| ∆ |)
end
{ limit the maximum displacement to the temperature t }
{ and then prevent from being displaced outside frame}
for v in V do begin
v.pos := v.pos + ( v. disp/ |v.disp|) * min ( v.disp, t );
v.pos.x := min(W/2, max(-W/2, v.pos.x));
v.pos.y := min(L/2, max(–L/2, v.pos.y))
end
{ reduce the temperature as the layout approaches a better configuration }
t := cool(t)
end
*/
