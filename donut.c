                        #include <stdio.h>/*----*/
                    #include <math.h>/*-------------*/
                #include <unistd.h>/*-------------------*/
              #include <time.h>/*-------------------------*/
             char* AR=" .:-=+*%#@";int ARS=10;typedef struct{
          float x,y,z;}V;float cl(float a,float n,float x){return
         (a)<(n)?(n):((a)>(x)?(x):(a));}float st(float e,float x){
       return(x)<(e)?0.0f:1.0f;}float ln(V v){return sqrt(v.x*v.x+v.y*
     v.y+v.z*v.z);}V nz(V v){float l=ln(v);return (V){v.x/l,v.y/l,v.z/l}
    ;}float d(V a,V b){return a.x*b.x+a.y*b.y+a.z*b.z;}float sd(V p,V t)
   {V q={sqrt(p.x*p.x+p.z*p.z)-t.x,p.y-t.y,0.0f};return sqrt(q.x*q.x+q.y
 *q.y)-t.y;}V r(V v,float th,V a){float c=cos(th);float s=sin(th);return
 (V){(c+(1-c)*a.x*a.x)*v.x+((1-c)*a.x*a.y-s*a.z)*v.y+((1-c)*a.x*a.z+s*a.
y)*v.z,((1-c)*a.y*a.x+s*a.z)*v.x          +(c+(1-c)*a.y*a.y)*v.y+((1-c)*a.
y*a.z-s* a.x)*v.z,((1-c)*a.z*a              .x-s*a.y)*v.x+((1-c)*a.z*a.y+s
*a.x)*v.y+(c+(1-c)*a.z*a.z)*                  v.z};}int main(){int W=64,H=
32;float tm=0;while(1){puts                     ("\033[H\033[J");for(int y
=0;y<H;y++){for(int x=0;x                       <W;x++){V st={x/(float)W,(H
-y)/(float)H,0.0f};V uv={                       st.x*2.0f-1.0f,st.y*2.0f-1.f
,0.0f};V tr={1.5f,0.5f,0.0f                      };V ro={0.0f,0.0f,3.0f};V
rd={uv.x,uv.y,-1.0f};V ld=                      nz((V){0.0f, 1.0f, 1.0f});
ro=r(ro,tm*0.5f,(V){1.0f,0.f                  ,0.0f});rd=r(rd,tm*0.5f,(V)
{1.0f,0.0f,0.0f});ld=r(ld,tm*               .5f,(V){1.0f,0.0f,0.0f});ro=r
(ro,tm*0.3f,(V){0.0f,1.0f,0.0f});          rd=r(rd,tm*0.3f,(V){0.0f,1.0f,
0.f});ld=r(ld,tm*0.3f,(V){0.0f,1.0f,0.0f});ro=r(ro,tm*0.2f,(V){0.0f,0.0f,
 1.0f});rd=r(rd,tm*0.2f,(V){0.0f,0.0f,1.0f});ld=r(ld,tm*0.2f,(V){0.0f,0.f
   ,1.0f});V p=ro;float t=0.0f;for(int i=0;i<100;i++){p=(V){ro.x+rd.x*t,
    ro.y+rd.y*t,ro.z+rd.z*t};float d=sd(p,tr);t+=d;if(t<0.01f||t>100.f
     )break;}float e=0.001f;V nm=nz((V){sd((V){p.x+e,p.y,p.z},tr)-sd((
      V){p.x-e,p.y,p.z},tr),sd((V){p.x,p.y+e,p.z},tr)-sd((V){p.x,p.y
        -e,p.z},tr),sd((V){p.x,p.y,p.z+e},tr)-sd((V){p.x,p.y,p.z-e
          },tr)});t/=40.0f;t=cl(t,0.0f,1.0f);t=1.0f-t;t*=fmax(
            .2f,d(nm, ld));putchar(AR[(int)(t * (ARS - 1))]);}
              printf("\n");}usleep(10000);tm+=0.02f;}return 0
                ;}/*------------------------------------*/
                   /*donut.c - Created by Ahmet Yigit*/
                        /*----------------------*/
