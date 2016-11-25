
DOGS_INNERps.dll: dlldata.obj DOGS_INNER_p.obj DOGS_INNER_i.obj
	link /dll /out:DOGS_INNERps.dll /def:DOGS_INNERps.def /entry:DllMain dlldata.obj DOGS_INNER_p.obj DOGS_INNER_i.obj \
		kernel32.lib rpcndr.lib rpcns4.lib rpcrt4.lib oleaut32.lib uuid.lib \

.c.obj:
	cl /c /Ox /DWIN32 /D_WIN32_WINNT=0x0400 /DREGISTER_PROXY_DLL \
		$<

clean:
	@del DOGS_INNERps.dll
	@del DOGS_INNERps.lib
	@del DOGS_INNERps.exp
	@del dlldata.obj
	@del DOGS_INNER_p.obj
	@del DOGS_INNER_i.obj
