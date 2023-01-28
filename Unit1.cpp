//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap*bmap = new Graphics::TBitmap;
TColor clr;
unsigned lum, maxlum;
float k=0.8;
int xlum, ylum;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   Height=Screen->Height*k;
   Width=Screen->Width*k;
   Form1->Constraints->MinHeight=Screen->Height*k;
   Form1->Constraints->MinWidth=Screen->Width*k;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N3Click(TObject *Sender)
{
   Application->Terminate();        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N1Click(TObject *Sender)
{
   if(OpenPictureDialog1->Execute())
   {
     Chart1->Visible=false;
     Image1->Visible=true;
     bmap->LoadFromFile(OpenPictureDialog1->FileName);
     //Image1->Picture->LoadFromFile(OpenPictureDialog1->FileName);
     Image1->Picture->Graphic=bmap;
     //Image1->Width=bmap->Width;
     //Image1->Height=bmap->Height;
     if (bmap->Width > Width || bmap->Height > Height)
      {
        //Image1->Width=0.8*Image1->Width;
        //Image1->Height=0.8*Image1->Height;
      }
     Image1->Cursor=crCross;
     Label1->Visible=false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1DblClick(TObject *Sender)
{

   //Form2->Height=bmap->Height;
   //Form2->Width=bmap->Width;

   //Form2->Image1->Width=bmap->Width;
   //Form2->Image1->Height=bmap->Height;
     //Form2->Image1->Width=Screen->Width;
   //Form2->Constraints->MinHeight=Screen->Height*2/3;
   //Form2->Constraints->MinWidth=Screen->Width*2/3;
   //Form2->Constraints->MaxHeight=Screen->Height*2/3;
   //Form2->Constraints->MaxWidth=Screen->Width*2/3;

   //Form2->Position=poDesktopCenter;
   //Form2->Image1->Width=Screen->Height*bmap->Width/bmap->Height*0.95;
   //Form2->Image1->Height=Screen->Height*0.95;
   Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Label1->Visible=true;
    Label1->Left=X+20;
    Label1->Top=Y-5; 
    Label1->Caption=(" "+IntToStr(X)+","+IntToStr(Y));

    bmap->LoadFromFile(OpenPictureDialog1->FileName);
    Image1->Picture->Graphic=bmap;

    for (int xline=0;xline<bmap->Width;xline++)
    Image1->Canvas->Pixels[xline][Y] = (TColor) RGB(255,0,0);
    ylum=Y;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::N2Click(TObject *Sender)
{
   Chart1->Visible=true;
   Image1->Visible=false;
   lum=0;
   xlum=0;
   maxlum=0;
   Series1->Clear();

   bmap->LoadFromFile(OpenPictureDialog1->FileName);
   Image1->Picture->Graphic=bmap;

   Timer1->Enabled=true;
   Chart1->BottomAxis->Maximum=bmap->Width;
   /*  for (int xlum=0;xlum<bmap->Width;xlum++)
   {
     clr=Image1->Picture->Bitmap->Canvas->Pixels[xlum][ylum];
     lum=(GetRValue(clr)*77+GetRValue(clr)*151+GetBValue(clr)*28)>>8;
     Series1->AddXY(xlum,lum);


   }
   */    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
   Chart1->Visible=false;
   Image1->Visible=true;
   Label1->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
     if (xlum<bmap->Width)
     {

     clr=Image1->Picture->Bitmap->Canvas->Pixels[xlum][ylum];
     lum=(GetRValue(clr)*77+GetRValue(clr)*151+GetBValue(clr)*28)>>8;
     if (lum > maxlum) maxlum=lum;
     Series1->AddXY(xlum,lum);
     xlum++;
     StatusBar1->SimpleText="Выполняется анализ. Завершено "+FloatToStrF(100.0*xlum/bmap->Width,ffFixed,7,2)+" %";
     }
     else
     Timer1->Enabled=false;
}
//---------------------------------------------------------------------------


