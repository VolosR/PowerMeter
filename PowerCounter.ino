#include <TFT_eSPI.h>
#include "Latin_Hiragana_24.h"
#include "NotoSansBold15.h"
#include "NotoSansMonoSCB20.h"
TFT_eSPI tft = TFT_eSPI();  
TFT_eSprite sprite= TFT_eSprite(&tft);


#define latin Latin_Hiragana_24
#define small NotoSansBold15
#define digits NotoSansMonoSCB20

#define c1 0xE73C //white
#define c2 0x18C3  //gray
#define c3 0x9986 //red
#define c4 0x2CAB  //green
#define c5 0xBDEF //gold

int fromTop=34;
int left=40;
int width=240;
int heigth=80;

uint16_t grays[60]={0};
uint16_t lines[11]={0};
int sec=0;
int pos=0;

int digit1=0;
int digit2=0;
int digit3=0;
int digit4=0;

long start=0;
long end=0;
int counter=0;
double fps=0;

int longLine=4;
int animationTimer=0;

void setup() {

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
 
 for(int i=0;i<50;i++)
  grays[i]=tft.color565(i*5, i*5, i*5);

lines[0]=grays[5]; lines[1]=grays[10]; lines[2]=grays[20]; lines[3]=grays[30]; lines[4]=grays[40]; lines[5]=grays[49];
lines[6]=grays[40]; lines[7]=grays[30]; lines[8]=grays[20]; lines[9]=grays[10]; lines[10]=grays[5];

 
sprite.createSprite(320,170);
sprite.setTextDatum(4);


}

void draw()
{

  if(counter==0)
start=millis();
counter++;

if(counter==100)
{
  end=millis();
  fps=100/((end-start)/1000.00);
  counter=0;
}
sprite.fillSprite(c1);

sprite.fillSmoothRoundRect(left+30,fromTop-20,width-60,heigth,8,c2,c1);
sprite.fillSmoothRoundRect(left+32,fromTop-18,width-64,heigth,8,c1,c2);
sprite.fillRect(left+30,fromTop-3,width-60,3,c1);
sprite.fillRect(left+80,fromTop-21,width-160,4,c1);



sprite.fillSmoothRoundRect(left,fromTop,width,heigth,8,c2,c1);

sprite.fillSmoothRoundRect(220,fromTop,60,heigth,8,c3,c1);
sprite.fillRect(219,fromTop,4,heigth,c1);

sprite.fillSmoothCircle(220, fromTop+heigth, 9, c1);
sprite.fillSmoothCircle(220, fromTop+heigth, 5, c2);


for(int i=0;i<4;i++){
sprite.fillRectHGradient(left+(20)+(i*36), fromTop+12, 15, 44, TFT_BLACK,grays[2]);
sprite.fillRectHGradient(left+(35)+(i*36), fromTop+12, 15, 44, grays[2],TFT_BLACK);

for(int j=0;j<11;j++)
if(j==5)
sprite.drawLine(left+(40)+(i*36),fromTop+14+(j*4),left+(47)+(i*36),fromTop+14+(j*4),lines[j]);
else
sprite.drawLine(left+(43)+(i*36),fromTop+14+(j*4),left+(47)+(i*36),fromTop+14+(j*4),lines[j]);
}


sprite.fillRectHGradient(231, fromTop+12, 20, 44, TFT_BLACK,grays[2]);
sprite.fillRectHGradient(251, fromTop+12, 20, 44, grays[2],TFT_BLACK);

for(int j=0;j<11;j++)
if(j==longLine)
sprite.drawLine(262,fromTop+14+(j*4),269,fromTop+14+(j*4),lines[j]);
else
sprite.drawLine(265,fromTop+14+(j*4),269,fromTop+14+(j*4),lines[j]);


sprite.drawLine(left+28,fromTop+60,left+28,fromTop+66,c1);
sprite.drawLine(left+28,fromTop+66,left+32,fromTop+66,c1);

sprite.drawLine(left+78,fromTop+66,left+78,fromTop+60,c1);
sprite.drawLine(left+74,fromTop+66,left+78,fromTop+66,c1);

sprite.drawLine(left+102,fromTop+66,left+106,fromTop+66,c1);
sprite.drawLine(left+102,fromTop+66,left+102,fromTop+60,c1);

sprite.drawLine(left+144,fromTop+66,left+148,fromTop+66,c1);
sprite.drawLine(left+148,fromTop+66,left+148,fromTop+60,c1);

sprite.loadFont(latin);
sprite.setTextColor(c2,c1);
sprite.drawString("kWh",160,18);
sprite.unloadFont(); 

sprite.loadFont(small);
sprite.setTextColor(c1,c3);
sprite.drawString("x1",250,fromTop+68);
sprite.setTextColor(c1,c2);
sprite.drawString("x100",94,fromTop+68);
sprite.drawString("x10",164,fromTop+68);
sprite.setTextColor(c2,c1);
sprite.drawString("POWER",160,fromTop+96);
sprite.setTextColor(c3,c1);
sprite.drawString("0",62,fromTop+104);

sprite.setTextColor(c4,c1);
sprite.drawString("100%",272,fromTop+104);
sprite.drawString(String(fps),20,164);
sprite.unloadFont(); 

sprite.loadFont(digits);
sprite.setTextColor(c1,TFT_BLACK);
sprite.drawString(String(digit2),106,fromTop+35);
sprite.drawString(String(digit1),70,fromTop+35);
sprite.drawString(String(digit3),142,fromTop+35);
sprite.drawString(String(digit4),178,fromTop+35);
sprite.drawString(String(sec),249,fromTop+35);
sprite.unloadFont(); 

sprite.fillRect(70,fromTop+102,180,3,c4);
sprite.fillRect(190,fromTop+102,60,3,c2);

sprite.fillRect(60,fromTop+120,200,2,c3);
sprite.fillTriangle(265, fromTop+120, 255, fromTop+120, 252, fromTop+116, c3);
sprite.fillTriangle(265, fromTop+120, 255, fromTop+120, 252, fromTop+124, c3);

sprite.fillSmoothRoundRect(80,fromTop+112,160,17,10,c2,c1);
sprite.drawRect(100,fromTop+116,120,8,TFT_BLACK);
sprite.fillRectHGradient(101, fromTop+117, 59, 6, grays[1],grays[44]);
sprite.fillRectHGradient(160, fromTop+117, 59, 6, grays[44],grays[1]);



for(int i=0;i<11;i++)
{
sprite.fillRect(102+(i*10)+pos,fromTop+118,2,4,c2);
}

sprite.pushSprite(0,0);
}


void loop() {
  draw();
  sec++;
  if(sec==100)
  {sec=0;
  digit4++;
  if(digit4==10){digit4=0; digit3++;}
  if(digit3==10){digit3=0; digit2++;}
  if(digit2==10){digit2=0; digit1++;}
  }

  pos++;
  if(pos==10)
  pos=0;

  animationTimer++;
  if(animationTimer==4)
  {
    animationTimer=0;
    longLine++;
    if( longLine==11)
    longLine=0;
  }  
}
