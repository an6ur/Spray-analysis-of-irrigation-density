object Form2: TForm2
  Left = 558
  Top = 297
  Width = 599
  Height = 368
  HorzScrollBar.Tracking = True
  VertScrollBar.Tracking = True
  Align = alClient
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnActivate = FormActivate
  OnKeyPress = FormKeyPress
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 489
    Height = 81
    AutoSize = True
    Stretch = True
    OnMouseDown = Image1MouseDown
  end
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 32
    Height = 13
    Caption = 'Label1'
    Color = clWhite
    ParentColor = False
  end
end
