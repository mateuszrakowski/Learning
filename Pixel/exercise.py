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
            crop = dict[body_part]
            print(*crop[:-1], sep = ", ", end="")
            print(" and ", end="")
            print(*crop[-1:], end="")
        else:
            print(*dict[body_part], sep = " and ", end="") 
        print("\n")
 
implement_me(body_parts)
