#!bin/bash

destination_folder = "home/jason/Fall-2023-Notes/static"

echo "Choose a File to Move to Fall-2023 Static Folder"

read f_name

echo "Ok, trying to move | $f_name"

mv $f_name ("../../../../.." + $destination_folder)

pwd