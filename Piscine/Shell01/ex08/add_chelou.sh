#!bin/sh
echo "obase=13; ibase=5;" $FT_NBR1 + $FT_NBR2  | sed "s/\'/0/g" | sed 's/\\/1/g;s/\"/2/g;s/\?/3/g;s/\!/4/g' | tr 'mrdoc' '01234' | sed 's/3base/obase/g' | bc | tr '0123456789ABC' 'gtaio luSnemf'
