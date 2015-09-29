from operator import itemgetter
import sys

if __name__ == "__main__":
    text = "LIRUMMIMMIVDMIXZIFFZIDMAZIFLDFLDVXUCIFULPCOUSBDBIMDBUXUCCDHLISLIMFPOOOPGIVPSFLIOPBLFDZPSBUQBUOVFLDFCDVIPFMHIDZIZPSGPMPEOIVUFPFHDMFLIUSIFLPSBLIOUGIVXUCCDLPMRZIXPUAMXUCCDDSVLIFDOKIVFUPFXUCCDIGISHLISPFHDMSUFHPFLLPCVUFQUZLIKIRFPFLPVVISMDQIPSDLUOIUSLPMPMODSVXUCCDINXIRFHLISLIHDMLASFPSBUZMRYPSBUSFLIUZXMUQFLICPSIMVUFCDYEILIHUAOVLDGIDFFDXKIVEPOEUDFUSXIXUCCDPQFLIZPSBLDVEIISUSLPCHLISFLIYCIFEAFPFHDMSUFXUCCDDSVFLILUEEPFLIOVPSLPMLDSVDSIOGPMLKSPQIXUCCDHLPXLMIZGIVLPCDMDMHUZV"
    character_count = {}
    frequency_of_letters = "ETAOINSHRDLCUMWFGYPBVKJXQZ"
    alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    for c in text:
        character_count.setdefault(c, 0)
        character_count[c] += 1

    sorted_character_count = sorted(character_count.items(), key=itemgetter(1), reverse=True)

    for key,value in sorted_character_count:
        print key + ": " + str(value)

    # for c in alphabet:
    #     print c + ": " + str(text.count(c + c))

    for c in alphabet:
        print c + ": " + str(alphabet.index(c))

    cipher = {}

    # for index, (key,value) in enumerate(sorted_character_count):
    #     cipher[key] = frequency_of_letters[index]
    #     print key + " -> " + cipher[key] + "= " + str(alphabet.index(cipher[key]) - alphabet.index(key))

#comma
    cipher["X"] = "C"
    cipher["U"] = "O"
    cipher["C"] = "M"
    cipher["D"] = "A"

#most common
    cipher["I"] = "E"
    #COMEfO -> COMETO
    cipher["F"] = "T"
    #TlE -> THE
    cipher["L"] = "H"
    #ATTACkED -> ATTACKED
    cipher["K"] = "K"
    #ANDHETAoKED -> ANDHETALKED
    cipher["O"] = "L"

    #ANDHETALKEDTOpT -> ANDHETALKEDTOIT
    cipher["P"] = "I"

    #HEONETHINb -> HEONETHING
    cipher["B"] = "G"

    #THATHADCOMETOHIMLONGAGEmAGO
    cipher["M"] = "S"

    #LIgEDINTHELIGHT
    cipher["G"] = "V"

    #hHENHESTILLLIVEDINTHELIGHT
    cipher["H"] = "W"

    #INVISIeLE
    cipher["E"] = "B"

    #ITWASTHEONETHINGHELOVED,HISrzECIOaS
    cipher["R"] = "P"
    cipher["Z"] = "R"
    cipher["A"] = "U"

    #qORHEKEPTITHIDDENSAqEINAHOLEONHISISLAND
    cipher["Q"] = "F"

    #EnCEPTWHENHEWASHUNTING
    cipher["N"] = "X"

    #MAyBEHEWOULDHAVEATTACKEDBILBOATONCE
    cipher["Y"] = "Y"


#testing and
    cipher["S"] = "N"
    cipher["V"] = "D"


    plain_text = []

    for c in text:
        if cipher.get(c):
            plain_text.append(cipher[c])
        else:
            plain_text.append(c.lower())

    print "This is the cipher"
    for (key, value) in cipher.items():
        print key + ": " + value

    print("".join(cipher.keys()))
    print("".join(cipher.values()))
    print(len(cipher.values()))


    print("".join(plain_text))

    print("".join(plain_text).replace("COMMA",",").replace("DOT","."))

    #http://www3.nd.edu/~busiforc/handouts/cryptography/cryptography%20hints.html

    #HE POSSESSED A SECRET TREASURE THAT HAD COME TO HIM LONG AGES AGO, WHEN HE STILL LIVED IN THE LIGHT A RING OF GOLD
    #THAT MADE ITS WEARER INVISIBLE.IT WAS THE ONE THING HE LOVED, HIS PRECIOUS, AND HE TALKED TO IT, EVEN WHEN IT WAS
    #NOT WITH HIM. FOR HE KEPT IT HIDDEN SAFE IN A HOLE ON HIS ISLAND, EXCEPT WHEN HE WAS HUNTING OR SPYING ON THE ORCS
    #OF THE MINES. MAYBE HE WOULD HAVE ATTACKED BILBO AT ONCE, IF THE RING HAD BEEN ON HIM WHEN THEY MET BUT IT WAS NOT,
    #AND THE HOBBIT HELD IN HIS HAND AN ELVISH KNIFE, WHICH SERVED HIM AS A SWORD.


#67d7a30e38974fe4f854f6d644b4cb18





