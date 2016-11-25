

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Sat Aug 06 13:20:48 2011
 */
/* Compiler settings for .\DOGS_INNER.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DOGS_INNER_h__
#define __DOGS_INNER_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __Idog_FWD_DEFINED__
#define __Idog_FWD_DEFINED__
typedef interface Idog Idog;
#endif 	/* __Idog_FWD_DEFINED__ */


#ifndef __Ikennel_FWD_DEFINED__
#define __Ikennel_FWD_DEFINED__
typedef interface Ikennel Ikennel;
#endif 	/* __Ikennel_FWD_DEFINED__ */


#ifndef __dog_FWD_DEFINED__
#define __dog_FWD_DEFINED__

#ifdef __cplusplus
typedef class dog dog;
#else
typedef struct dog dog;
#endif /* __cplusplus */

#endif 	/* __dog_FWD_DEFINED__ */


#ifndef __kennel_FWD_DEFINED__
#define __kennel_FWD_DEFINED__

#ifdef __cplusplus
typedef class kennel kennel;
#else
typedef struct kennel kennel;
#endif /* __cplusplus */

#endif 	/* __kennel_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __Idog_INTERFACE_DEFINED__
#define __Idog_INTERFACE_DEFINED__

/* interface Idog */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Idog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77CCBBE1-3699-11D5-AEA3-00A0D2162638")
    Idog : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Run( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Bark( 
            /* [in] */ LONG nTime) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sleep( 
            /* [in] */ LONG nTime) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Breed( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Breed( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HairColor( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_HairColor( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IdogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Idog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Idog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Idog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Idog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Idog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Idog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Idog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Run )( 
            Idog * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Bark )( 
            Idog * This,
            /* [in] */ LONG nTime);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sleep )( 
            Idog * This,
            /* [in] */ LONG nTime);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Breed )( 
            Idog * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Breed )( 
            Idog * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            Idog * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            Idog * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HairColor )( 
            Idog * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_HairColor )( 
            Idog * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IdogVtbl;

    interface Idog
    {
        CONST_VTBL struct IdogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Idog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Idog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Idog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Idog_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Idog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Idog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Idog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Idog_Run(This)	\
    (This)->lpVtbl -> Run(This)

#define Idog_Bark(This,nTime)	\
    (This)->lpVtbl -> Bark(This,nTime)

#define Idog_Sleep(This,nTime)	\
    (This)->lpVtbl -> Sleep(This,nTime)

#define Idog_get_Breed(This,pVal)	\
    (This)->lpVtbl -> get_Breed(This,pVal)

#define Idog_put_Breed(This,newVal)	\
    (This)->lpVtbl -> put_Breed(This,newVal)

#define Idog_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define Idog_put_Name(This,newVal)	\
    (This)->lpVtbl -> put_Name(This,newVal)

#define Idog_get_HairColor(This,pVal)	\
    (This)->lpVtbl -> get_HairColor(This,pVal)

#define Idog_put_HairColor(This,newVal)	\
    (This)->lpVtbl -> put_HairColor(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Idog_Run_Proxy( 
    Idog * This);


void __RPC_STUB Idog_Run_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Idog_Bark_Proxy( 
    Idog * This,
    /* [in] */ LONG nTime);


void __RPC_STUB Idog_Bark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Idog_Sleep_Proxy( 
    Idog * This,
    /* [in] */ LONG nTime);


void __RPC_STUB Idog_Sleep_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE Idog_get_Breed_Proxy( 
    Idog * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB Idog_get_Breed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE Idog_put_Breed_Proxy( 
    Idog * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB Idog_put_Breed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE Idog_get_Name_Proxy( 
    Idog * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB Idog_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE Idog_put_Name_Proxy( 
    Idog * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB Idog_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE Idog_get_HairColor_Proxy( 
    Idog * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB Idog_get_HairColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE Idog_put_HairColor_Proxy( 
    Idog * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB Idog_put_HairColor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Idog_INTERFACE_DEFINED__ */


#ifndef __Ikennel_INTERFACE_DEFINED__
#define __Ikennel_INTERFACE_DEFINED__

/* interface Ikennel */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_Ikennel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F77A0781-369E-11D5-AEA3-00A0D2162638")
    Ikennel : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR bstrFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR bstrFilename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCount( 
            /* [retval][out] */ LONG *nNumDogs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAt( 
            /* [in] */ LONG nIndex,
            /* [retval][out] */ Idog **pDog) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IkennelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Ikennel * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            Ikennel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            Ikennel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Ikennel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Ikennel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Ikennel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Ikennel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Save )( 
            Ikennel * This,
            /* [in] */ BSTR bstrFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Load )( 
            Ikennel * This,
            /* [in] */ BSTR bstrFilename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            Ikennel * This,
            /* [retval][out] */ LONG *nNumDogs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetAt )( 
            Ikennel * This,
            /* [in] */ LONG nIndex,
            /* [retval][out] */ Idog **pDog);
        
        END_INTERFACE
    } IkennelVtbl;

    interface Ikennel
    {
        CONST_VTBL struct IkennelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Ikennel_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define Ikennel_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define Ikennel_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define Ikennel_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define Ikennel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define Ikennel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define Ikennel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define Ikennel_Save(This,bstrFilename)	\
    (This)->lpVtbl -> Save(This,bstrFilename)

#define Ikennel_Load(This,bstrFilename)	\
    (This)->lpVtbl -> Load(This,bstrFilename)

#define Ikennel_GetCount(This,nNumDogs)	\
    (This)->lpVtbl -> GetCount(This,nNumDogs)

#define Ikennel_GetAt(This,nIndex,pDog)	\
    (This)->lpVtbl -> GetAt(This,nIndex,pDog)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ikennel_Save_Proxy( 
    Ikennel * This,
    /* [in] */ BSTR bstrFilename);


void __RPC_STUB Ikennel_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ikennel_Load_Proxy( 
    Ikennel * This,
    /* [in] */ BSTR bstrFilename);


void __RPC_STUB Ikennel_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ikennel_GetCount_Proxy( 
    Ikennel * This,
    /* [retval][out] */ LONG *nNumDogs);


void __RPC_STUB Ikennel_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Ikennel_GetAt_Proxy( 
    Ikennel * This,
    /* [in] */ LONG nIndex,
    /* [retval][out] */ Idog **pDog);


void __RPC_STUB Ikennel_GetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Ikennel_INTERFACE_DEFINED__ */



#ifndef __DOGS_INNERLib_LIBRARY_DEFINED__
#define __DOGS_INNERLib_LIBRARY_DEFINED__

/* library DOGS_INNERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DOGS_INNERLib;

EXTERN_C const CLSID CLSID_dog;

#ifdef __cplusplus

class DECLSPEC_UUID("77CCBBE2-3699-11D5-AEA3-00A0D2162638")
dog;
#endif

EXTERN_C const CLSID CLSID_kennel;

#ifdef __cplusplus

class DECLSPEC_UUID("F77A0782-369E-11D5-AEA3-00A0D2162638")
kennel;
#endif
#endif /* __DOGS_INNERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


