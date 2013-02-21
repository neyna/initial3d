#!/bin/sh

####################################################

GLM_VERSION=0.9.2.4
GLM_URL="http://sourceforge.net/projects/ogl-math/files/glm-$GLM_VERSION/glm-$GLM_VERSION.zip"
GLM_ARCHIVE="glm-$GLM_VERSION.zip"


####################################################
system_name=`uname -a`

echo "-----------------------------------------------"
echo "Downloading external lib."
echo "-----------------------------------------------\n"

if [ ! -d "glm-$GLM_VERSION" ]; then
    echo "downloading GLM $GLM_VERSION library"
    case $system_name in
        Darwin*)
            curl -L $GLM_URL -o $GLM_ARCHIVE
            ;;
        *)
            wget $GLM_URL -O $GLM_ARCHIVE
            ;;
    esac
    unzip $GLM_ARCHIVE
    rm $GLM_ARCHIVE
else
    echo "glm-$GLM_VERSION already installed.\n"
fi

echo "-----------------------------------------------\n"