# Input data
body_parts = {
    'head': ['brain', 'ear', 'nose'],
    'torso': ['kidney', 'heart', 'lungs'],
    'legs': ['knee', 'toe']
}
 
# Expected output
"""
Body Parts:
 
head:
brain, ear and nose
 
torso:
kidney, heart and lungs
 
legs:
knee and toe
"""
 
def implement_me(dict):
    print("\nBody Parts:\n")

    for body_part in dict:
        print(body_part + ":")
        if len(dict[body_part]) > 2:
            organs = ", ".join(dict[body_part][:-1])
            print(organs + f" and {dict[body_part][-1]}")
        else:
            organs_and = " and ".join(dict[body_part])
            print(organs_and)
        print("\n")
 
implement_me(body_parts)
