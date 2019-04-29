#include<LNDZ.h>
#include<YAX.h>
int ll,l,m,r,rr,pl,pr,pll,prr;
void close(servo jz)
{
 jz.work(-10,0);
 delay(1000);
 jz.work(10,0);
 delay(1000);
 jz.work(0,0);
}
void open(servo jz){
  jz.work(-10,0);
  delay(1000);
  jz.work(0,-6);
}
void findline()
{
  ll=AR(4)<418;
  l=AR(2)<349;
  m=AR(1)<329;
  r=AR(3)<183;
  rr=AR(5)<301;  
}
void bl(){
  findline(); 
  if(ll==0)motor(-60,60);
  else if(l==0)motor(-40,40);
  else if(m==0)motor(45,45);
  else if(r==0)motor(40,-40);
  else if(rr==0)motor(60,-60);
}
void bm(){
  findline(); 
  if(m==0)motor(45,45);
  else if(ll==0)motor(-60,60);
  else if(l==0)motor(-40,40);
  else if(r==0)motor(40,-40);
  else if(rr==0)motor(60,-60);
}
void br(){
  findline();
  if(rr==0)motor(60,-60);
  else if(r==0)motor(40,-40); 
  else if(ll==0)motor(-60,60);
  else if(l==0)motor(-40,40);
  else if(m==0)motor(45,45);
}
void wl(){
findline();
  if(ll)motor(-60,60);
  else if(l)motor(-40,40);
  else if(m)motor(40,40);
  else if(r)motor(40,-40);
  else if(rr)motor(60,-60);
}
void wm(){
findline();
  if(m)motor(40,40);
  else if(ll)motor(-60,60);
  else if(l)motor(-40,40);
  else if(r)motor(40,-40);
  else if(rr)motor(60,-60);
}
void wr(){
findline();
  if(rr)motor(60,-60);
  else if(r)motor(40,-40);
  else if(m)motor(40,40);
  else if(ll)motor(-60,60);
  else if(l)motor(-40,40);
}
void seeline(lc seer){

seer.setCursor(0,1);
seer.print(AR(4));
seer.setCursor(0,0);
seer.print(AR(2));
seer.setCursor(7,0);
seer.print(AR(1));
seer.setCursor(12,0);
seer.print(AR(3));
seer.setCursor(12,1);
seer.print(AR(5));
}
void testline(lc seer){
findline();
 seer.setCursor(0,1);
seer.print(ll);
seer.setCursor(0,0);
seer.print(l);
seer.setCursor(7,0);
seer.print(m);
seer.setCursor(12,0);
seer.print(r);
seer.setCursor(12,1);
seer.print(rr);
}
void pjz(lc seer){
  int llt,lt,mt,rt,rrt;
    llt = AR(4);
    lt = AR(2);
    mt =AR(1);
    rt = AR(3);
    rrt = AR(5);
delay(1000);
    seer.clear();
    seer.print("5");
    seer.print("s");
delay(1000);
    seer.clear();
    seer.print("4");
    seer.print("s");
delay(1000);
    seer.clear();
    seer.print("3");
    seer.print("s");
delay(1000);
    seer.clear();
    seer.print("2");
    seer.print("s");
delay(1000);
    seer.clear();
    seer.print("1");
    seer.print("s");
delay(1000);
    seer.clear();
    seer.print("test");
delay(500);
    seer.clear();
seer.setCursor(0,1);
seer.print((AR(4)+llt)/2);
seer.setCursor(0,0);
seer.print((AR(2)+lt)/2);
seer.setCursor(7,0);
seer.print((AR(1)+mt)/2);
seer.setCursor(12,0);
seer.print((AR(3)+rt)/2);
seer.setCursor(12,1);
seer.print((AR(5)+rrt)/2);

}
void turn(int left,int right)
{
  int n=0;
  motor(left,right);
  while(1){
  findline();
  if(m==1&&n==0){  
    n=1;
    }
    if(n==1&&m==0){
      motor(0,0);
      break;
    }
  }
}
void turnw(int left,int right)
{
  int n=0;
  motor(left,right);
  while(1){
  findline();
  if(m==0&&n==0){  
    n=1;
    }
    if(n==1&&m==1){
      motor(0,0);
      break;
    }
  }
}
void fl(){
 pll= DR(4);
 pl = DR(2);
 pr = DR(3);
 prr = DR(5);
}
void back()
{
  fl();
  if(pll==0)fmotor(-60,60);
  else if(pl==0)fmotor(-40,40);
  else if(prr==0)fmotor(60,-60);
  else if(pr==0)fmotor(40,-40);
  else fmotor(30,30);
}
void fmotor(int right,int left)
{
 motor(-left,-right);
}

void times::start()
{
   TIMES = millis();
}
int times::stop()
{
   return (millis()-TIMES)/1000;
}
