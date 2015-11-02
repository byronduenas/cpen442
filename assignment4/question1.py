import hashlib

for x in xrange(0, 9999):
    number = str(x).zfill(4)
    hash1 = hashlib.sha1(number + "ug").hexdigest()
    hash2 = hashlib.sha1("ug" + number).hexdigest()
    if hash1 == "7FE36DBE8F148316349EC3435546DB4076FE195F".lower():
        print number + "ug" + " is the password"
        break
    elif hash2 == "7FE36DBE8F148316349EC3435546DB4076FE195F".lower():
        print "ug" + number + " is the password"
        break

# ug0812