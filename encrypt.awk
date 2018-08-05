#!/usr/bin/env awk -f

BEGIN {
    printf "Enter password: " > "/dev/stderr"
    getline password < "-"
}

/\/\/\}/{
    flag = 0
}

flag && length($0) {
    if (enc) {
        cmd = "openssl enc -e -bf -salt -a -A -k " password
        match($0, /^[ ]+/, arr)
        num = length(arr[0])
        if (num > 0) {
            printf "%*c", num, " "
        }
    } else {
        cmd = "openssl enc -d -bf -salt -a -A -k " password
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
