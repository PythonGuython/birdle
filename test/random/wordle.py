with open('wordle-answers-alphabetical.txt', 'r') as f:
     words = f.readlines()
     words = [word[:-1] for word in words]

curated_words = []

for word in words:
    if len(set(word)) == 5:
        curated_words.append(word)

print("number of words in list", len(words))
print("number of words in list that don't repeat letters", len(curated_words))


