 #include<stdio.h>
#include<conio.h>
#include<dos.h>

/* returns scan code of the key that has been hit */
getkey()
{
union REGS i,o;
while(!kbhit() )
;
i.h.ah=0;
int86(22,&i,&o);
return(o.h.ah);
}


void main() {

int i,j,a[16]={1,4,15,7,8,10,2,11,14,3,6,13,12,9,5,0};
int temp,h,moves=0,won=0;

clrscr();


/****************************************************/


do {
  /**************/
  /* to move up */
  /**************/

if(h==72) {


for(i=0;i<16;i++) {
if(a[i]==0){
if(a[0]==0 || a[1]==0 || a[2]==0 || a[3]==0) {
break;
}
temp=a[i];
a[i]=a[i-4];
a[i-4]=temp;
moves=moves+1;
break;
}
}
 }
  /****************/
  /* to move left */
  /****************/

if(h==75) {

for(i=0;i<16;i++) {

if(a[i]==0){
if(a[0]==0 || a[4]==0 || a[8]==0 || a[12]==0) {
break;
}
temp=a[i];
a[i]=a[i-1];
a[i-1]=temp;
moves=moves+1;
break;
}
}
 }

  /****************/
  /* to move down */
  /****************/

if(h==80) {
for(i=0;i<16;i++) {
if(a[i]==0){
if(a[12]==0 || a[13]==0 || a[14]==0 || a[15]==0) {
break;
}
temp=a[i];
a[i]=a[i+4];
a[i+4]=temp;
moves=moves+1;
break;
}
}
 }
 /*****************/
 /* to move right */
 /*****************/

if(h==77) {

for(i=0;i<16;i++) {

if(a[i]==0) {

if(a[3]==0 || a[7]==0 || a[11]==0 || a[15]==0 ) {
break;
}

temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
moves=moves+1;
break;
}
 }
  }

/***********************************************************/

       /**********************************/
       /* printing the puzzle with boxes */
       /**********************************/

printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,194,196,196,196,194,196,196,196,194,196,196,196,191);
for(i=0;i<=15;i++) {

printf("%c",179);

if(a[i]==0) {
printf("%c  ",32);     /* printing a blank space in the puzzle */
}
if(a[i]!=0)

printf(" %2d",a[i]);

if(a[i]==a[3] || a[i]==a[7] || a[i]==a[11] || a[i]==a[15])
printf("%c",179);

if(i==3||i==7||i==11)
printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",195,196,196,196,197,196,196,196,197,196,196,196,197,196,196,196,180);

if(a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5 && a[5]==6
&&a[6]==7 && a[7]==8 && a[8]==9 && a[9]==10 && a[11]==12 && a[12]==13
&& a[13]==14 && a[14]==15 && a[15]==0 ) {

won=1;
}

 }
printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,193,196,196,196,193,196,196,196,193,196,196,196,217);

/***************************************************/
if(won==1) {
printf("\n\n\tCongratulations! you have won.");
break;
}
      /**********************************/
      /* to print instructions for user */
      /**********************************/

printf("\n\n\n\n\n\n  Total Moves: %d\t\t\t\t  Use arrow keys to move blank:\n\n",moves);
printf("\t\t\t\t\t\t  %c to move up\n",30);
printf("\t\t\t\t\t\t  %c to move down\n",31);
printf("\t\t\t\t\t\t  %c to move left\n",17);
printf("\t\t\t\t\t\t  %c to move right\n",16);

/****************************************************/

     /**********************/
     /* to take user input */
     /**********************/

h=getkey();
clrscr();

/****************************************************/

}while(h==72 || h==75 || h==77 ||h==80);


getch();

}
