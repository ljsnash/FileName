

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0620 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for FileName.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0620 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __FileName_h_h__
#define __FileName_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFileName_FWD_DEFINED__
#define __IFileName_FWD_DEFINED__
typedef interface IFileName IFileName;

#endif 	/* __IFileName_FWD_DEFINED__ */


#ifndef __FileName_FWD_DEFINED__
#define __FileName_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileName FileName;
#else
typedef struct FileName FileName;
#endif /* __cplusplus */

#endif 	/* __FileName_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __FileName_LIBRARY_DEFINED__
#define __FileName_LIBRARY_DEFINED__

/* library FileName */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_FileName;

#ifndef __IFileName_DISPINTERFACE_DEFINED__
#define __IFileName_DISPINTERFACE_DEFINED__

/* dispinterface IFileName */
/* [uuid] */ 


EXTERN_C const IID DIID_IFileName;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5C1DE705-C397-44B1-A140-2947147D6EBA")
    IFileName : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IFileNameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileName * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileName * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileName * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileName * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileName * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileName * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileName * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IFileNameVtbl;

    interface IFileName
    {
        CONST_VTBL struct IFileNameVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileName_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileName_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileName_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileName_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileName_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileName_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileName_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IFileName_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_FileName;

#ifdef __cplusplus

class DECLSPEC_UUID("1BDDFF32-E9C1-478C-A710-B8DA6AD43D3C")
FileName;
#endif
#endif /* __FileName_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


