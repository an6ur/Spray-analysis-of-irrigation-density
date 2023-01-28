//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
   
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormActivate(TObject *Sender)
{
   //Image1->Picture->Graphic=Form1->Image1->Picture->Graphic;
   //Image1->Cursor=crCross;
       
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormKeyPress(TObject *Sender, char &Key)
{
    if (Key==VK_ESCAPE) Close();

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   Label1->Caption=(IntToStr(X)+","+IntToStr(Y));
   Label1->Left=X+25;
   Label1->Top=Y-5;     
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
    
    Image1->Picture->Graphic=Form1->Image1->Picture->Graphic;
    Image1->Cursor=crCross;
}
//---------------------------------------------------------------------------
