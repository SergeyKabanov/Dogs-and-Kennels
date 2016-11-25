; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDogProps
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "DOGS_OUTER.h"
ODLFile=DOGS_OUTER.odl

ClassCount=5
Class1=CDOGS_OUTERApp
Class2=CDOGS_OUTERDlg
Class3=CAboutDlg
Class4=CDOGS_OUTERDlgAutoProxy

ResourceCount=6
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_DOGS_OUTER_DIALOG
Resource4=IDD_ABOUTBOX (English (U.S.))
Resource5=ID_DOGS_OUTER_DLG (English (U.S.))
Class5=CDogProps
Resource6=IDD_PROPERTIES_Dlg

[CLS:CDOGS_OUTERApp]
Type=0
HeaderFile=DOGS_OUTER.h
ImplementationFile=DOGS_OUTER.cpp
Filter=N

[CLS:CDOGS_OUTERDlg]
Type=0
HeaderFile=DOGS_OUTERDlg.h
ImplementationFile=DOGS_OUTERDlg.cpp
Filter=D
LastObject=IDOK
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=DOGS_OUTERDlg.h
ImplementationFile=DOGS_OUTERDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889
Class=CAboutDlg

[CLS:CDOGS_OUTERDlgAutoProxy]
Type=0
HeaderFile=DlgProxy.h
ImplementationFile=DlgProxy.cpp
BaseClass=CCmdTarget
Filter=N

[DLG:IDD_DOGS_OUTER_DIALOG]
Type=1
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Class=CDOGS_OUTERDlg

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=1
Control1=IDOK,button,1342373889

[DLG:ID_DOGS_OUTER_DLG (English (U.S.))]
Type=1
Class=CDOGS_OUTERDlg
ControlCount=2
Control1=IDOK,button,1342242827
Control2=IDC_DOGS_LIST,listbox,1352732931

[DLG:IDD_PROPERTIES_Dlg]
Type=1
Class=CDogProps
ControlCount=7
Control1=IDOK,button,1342242827
Control2=IDC_STATIC,static,1350570497
Control3=IDC_STATIC,static,1350570497
Control4=IDC_STATIC,static,1350570497
Control5=IDC_EDIT_NAME,edit,1350633601
Control6=IDC_EDIT_BREED,edit,1350633601
Control7=IDC_EDIT_HAIR,edit,1350631553

[CLS:CDogProps]
Type=0
HeaderFile=DogProps.h
ImplementationFile=DogProps.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDogProps

