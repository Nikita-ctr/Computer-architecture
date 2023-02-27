cmd_/home/nikita/APK/lab_1/Module.symvers := sed 's/\.ko$$/\.o/' /home/nikita/APK/lab_1/modules.order | scripts/mod/modpost -m -a  -o /home/nikita/APK/lab_1/Module.symvers -e -i Module.symvers   -T -
