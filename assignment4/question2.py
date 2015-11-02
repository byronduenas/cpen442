import hashlib

#kLD63B9C47BB91EFC78AAB6C4CA17E5F7798C1369C
all_characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-="
num_characters = len(all_characters)
max_combinations = pow(num_characters, 6)

for x in xrange(0, max_combinations):
    first_index = x / pow(num_characters, 5) % num_characters
    second_index = x / pow(num_characters, 4) % num_characters
    third_index = x / pow(num_characters, 3) % num_characters
    fourth_index = x / pow(num_characters, 2) % num_characters
    fifth_index = x / pow(num_characters, 1) % num_characters
    sixth_index = x / pow(num_characters, 0) % num_characters
    first_char = all_characters[first_index]
    second_char = all_characters[second_index]
    third_char = all_characters[third_index]
    fourth_char = all_characters[fourth_index]
    fifth_char = all_characters[fifth_index]
    sixth_char = all_characters[sixth_index]

    word = first_char + second_char + third_char + fourth_char + fifth_char + sixth_char
    hash1 = hashlib.sha1(word + "kL").hexdigest()
    hash2 = hashlib.sha1("kL" + word).hexdigest()
    if hash1 == "D63B9C47BB91EFC78AAB6C4CA17E5F7798C1369C".lower():
        print word + "kL" + " is the password"
        break
    elif hash2 == "D63B9C47BB91EFC78AAB6C4CA17E5F7798C1369C".lower():
        print "kL" + word + " is the password"
        break

#11:30am
# ug0812