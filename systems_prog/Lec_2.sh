#!bin/sh

f_name = "Lec_2_m.sh"

if [ -e Lec_2_m.sh ]
then
    echo "Already created!"
else
    touch f_name
    echo "#!bin/sh" > f_name
fi

sh "Lec_2_m.sh"

echo "Hello world"

