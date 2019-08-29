#!/usr/bin/env awk -f

BEGIN {
    printf "Enter password: " > "/dev/stderr"
    getline password < "-"
}

/\/\/\}/{
    flag = 0
}

flag && length($0) {
    match($0, /^[ ]+/, arr)
    num = length(arr[0])
    if (num > 0) {
        printf "%*c", num, " "
    }
    gsub(/^[ ]+/, "")

    if (enc) {
        cmd = "openssl enc -aes-128-cbc -e -pbkdf2 -iter 1000 -a -A -k " password
    } else {
        cmd = "openssl enc -aes-128-cbc -d -pbkdf2 -iter 1000 -a -A -k " password
    }

    print | cmd
    close(cmd)

    if (enc) {
        printf "\n"
    }
}

!flag || !length($0) {
    print
}

/\/\/\{/{
    flag = 1
}
