//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <ExtDlgs.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>
#include <Chart.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TOpenPictureDialog *OpenPictureDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *A1;
        TMenuItem *N1;
        TMenuItem *N2;
        TMenuItem *N3;
        TImage *Image1;
        TLabel *Label1;
        TChart *Chart1;
        TMenuItem *N4;
        TAreaSeries *Series1;
        TTimer *Timer1;
        TStatusBar *StatusBar1;
        void __fastcall N3Click(TObject *Sender);
        void __fastcall N1Click(TObject *Sender);
        void __fastcall Image1DblClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N4Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
