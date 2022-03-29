call setup_mssdk71.bat

cd .
nmake -f nasz_usb_servo_wzorzec.mk  MAT_FILE=1 ISPROTECTINGMODEL=NOTPROTECTING OPTS="-DON_TARGET_WAIT_FOR_START=0"
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
