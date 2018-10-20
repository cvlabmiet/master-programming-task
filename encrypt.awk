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
        cmd = "openssl enc -e -bf -S 2b6378ff -a -A -k " password
    } else {
        cmd = "openssl enc -d -bf -S 2b6378ff -a -A -k " password
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
