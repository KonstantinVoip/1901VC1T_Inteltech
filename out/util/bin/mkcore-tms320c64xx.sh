#!/bin/sh
# 
# Executes mkcore-tms320c64xx.exe to create LIF format file from TI OUT file.
#
# @param 1: relative path of OS_PATH environment to SVN repository.
# @param 2: relative path of OS_PATH environment to TI linked COFF OUT file.
# @param 3: relative path of OS_PATH environment to new creating LIF file.
# @param 4: major version. [optional]
# @param 5: minor version. [optional]
# @param 6: patch version. [optional]
#
# @author    Sergey Baigudin, sergey@baigudin.software
# @copyright 2017, Sergey Baigudin
UTIL_PAS="C:/1901VC1T_Inteltech/out/util/bin"
cd "${UTIL_PAS}" || exit 1

#cd "${OS_PATH}" || exit 1

if [[ "$#" -eq 3 ]]; then 

    revArg=$(svn info "$1" | grep Revision | tail -n1 | gawk '// {print $2}')
    [[ -z "$revArg" ]] && revArg=0
    
    version="v0.0.$revArg"
    
    if [[ "$revArg" -eq 0 ]]; then     
        echo "-------------------------------------------------------------------------------"
        echo " $version OF OS IS INCORRECT, OR SVN REPOSITORY IS NOT FOUND "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi 
    
    if [[ "$revArg" -gt 65535 ]]; then     
        echo "-------------------------------------------------------------------------------"
        echo " $version OF OS IS AN INCORRECT SVN SEMANTIC VERSION FOR THIS PROJECT "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi
    
elif [[ "$#" -eq 6 ]]; then     
    major="$4"
    minor="$5"
    build="$6"
    
    re='^[0-9]+$'
    if ! [[ "$major" =~ "$re" ]]; then
        echo "-------------------------------------------------------------------------------"
        echo " THE MAJOR SCRIPT PARAMETER 4 IS NOT A NUMBER "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi    
    
    re='^[0-9]+$'
    if ! [[ "$minor" =~ "$re" ]]; then
        echo "-------------------------------------------------------------------------------"
        echo " THE MINOR SCRIPT PARAMETER 5 IS NOT A NUMBER "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi

    re='^[0-9]+$'
    if ! [[ "$build" =~ "$re" ]]; then
        echo "-------------------------------------------------------------------------------"
        echo " THE PATCH SCRIPT PARAMETER 6 IS NOT A NUMBER "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi    
    
    version="v$major.$minor.$build"
    
    if [[ "$major" -gt 255 ]] || [[ "$minor" -gt 255 ]] || [[ "$build" -gt 65535 ]]; then     
        echo "-------------------------------------------------------------------------------"
        echo " $version OF OS IS AN INCORRECT GIT SEMANTIC VERSION FOR THIS PROJECT "
        echo "-------------------------------------------------------------------------------"
        exit 1
    fi
    
    revArg=`expr $major \* 16777216 + $minor \* 65536  + $build`
else
    echo "-------------------------------------------------------------------------------"
    echo " $# IS ILLEGAL QUANTITY OF PARAMETERS "
    echo "-------------------------------------------------------------------------------"
    exit 1
fi

${UTIL_PAS}/mkcore-tms320c64xx.exe "${revArg}" "${UTIL_PAS}/$2" "${UTIL_PAS}/$3"

#${OS_PATH}/bin/mkcore-tms320c64xx.exe "${revArg}" "${OS_PATH}/$2" "${OS_PATH}/$3"
  


echo "-------------------------------------------------------------------------------"
echo " LINKING $version OF OS HAS BEEN DONE "
echo "-------------------------------------------------------------------------------"
