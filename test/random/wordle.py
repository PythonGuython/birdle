import random
import json

with open('wordle-answers-alphabetical.txt', 'r') as f:
     words = f.readlines()
     words = [word[:-1] for word in words]

curated_words = []

for word in words:
    if len(set(word)) == 5:
        curated_words.append(word)

random.shuffle(curated_words)

print(json.dumps(curated_words))


