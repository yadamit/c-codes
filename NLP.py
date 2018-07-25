import json
import re

def tokenize(text):
    a=['1', '2', '3', '4', '5', '6', '7', '8', '9', '0'];
    split=re.split('\W+',text)
    stemmed=[ps.stem(i) for i in split if (not i in a) and (not i in stopwords.words('english'))]
    return stemmed #split text by non-alphanumeric chaachters

with open('train.json') as fin:
    trainjson=json.load(fin) # loading the data in a list of dictionaries

data_pos=[];
data_neg=[];
for i in range(0,len(trainjson)):
    if trainjson[i]['requester_received_pizza']==True:
        data_pos.append(trainjson[i]['request_text_edit_aware']);
    else:
        data_neg.append(trainjson[i]['request_text_edit_aware']);

from sklearn.feature_extraction.text import CountVectorizer
vec = CountVectorizer(tokenizer=tokenize)

data_total=vec.fit_transform(data_pos+data_neg).toarray()
data_pos=vec.fit_transform(data_pos).toarray()
data_neg=vec.fit_transform(data_neg).toarray()
freq_pos=sum(data_pos) #column wise sum of matrix
freq_neg=sum(data_neg)
freq_total=sum(data_total)
