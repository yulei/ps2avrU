make clean
make -f makefile_NKRO
del keymain_NKRO.hex
ren keymain.hex keymain_fn2LED_NKRO.hex
::pause;
make clean
make -f makefile_GKP
del keymain_GKP.hex
ren keymain.hex keymain_fn2LED_GKP.hex
::pause;
make clean
make -f makefile_NKRO_SL_apart
del keymain_NKRO_SL_apart.hex
ren keymain.hex keymain_fn2LED_NKRO_SL_apart.hex
::pause;
make clean
make -f makefile_GKP_SL_apart
del keymain_GKP_SL_apart.hex
ren keymain.hex keymain_fn2LED_GKP_SL_apart.hex
::pause;
go.bat
pause;