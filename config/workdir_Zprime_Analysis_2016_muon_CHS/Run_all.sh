#!/bin/bash

StringVal='
TTTo2L2Nu_2016v3_1.xml
TTTo2L2Nu_2016v3_2.xml
TTTo2L2Nu_2016v3_3.xml
TTTo2L2Nu_2016v3_4.xml
'
for val in $StringVal;



do
    sframe_main ${val}
done


