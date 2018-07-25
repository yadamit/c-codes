#!/bin/bash

ssh -f -N -R 0:localhost:22 wintern@172.26.83.102 &>file.txt && scp file.txt wintern@172.26.83.102
