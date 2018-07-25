import json
import nltk
import re
from nltk.corpus import stopwords
from nltk.stem import PorterStemmer
ps=PorterStemmer()
import csv
def frequency_count(foo):
    #returns a dictionary with frequency of ever word in input text
    split=re.split('\W+',foo)
    split=sorted(split)
    a=['1', '2', '3', '4', '5', '6', '7', '8', '9', '0'];
    #remove numbers and stopwords
    stemmed=[ps.stem(i) for i in split if (not i in a) and (not i in stopwords.words('english'))]
    #counting requency of each words
    frequency_counter={}
    for i in stemmed:
        frequency_counter[i]=0;
    total_words=0
    for i in stemmed:
        frequency_counter[i]=frequency_counter[i]+1;
        total_words=total_words+1
    return frequency_counter,total_words



with open('train.json') as fin:
    trainjson=json.load(fin) # loading the data in a list of dictionaries
with open('test.json') as fout:
    testjson=json.load(fout)
rcvd_pza='' #all text used by piza recievers
not_rcvd_pza='' #text used by non piza recievers
got_piza=0 #number of people got pizza
not_get_piza=0 #number of people did bot get pizza
rcvd_words=0 #number of words used by piza recievers
not_rcvd_words=0 #number of words used by non piza recievers
for i in range(0,len(trainjson)): #replace 10 by len(trainjhson)
    if trainjson[i]['requester_received_pizza']:
        #collect all the text by pizza recievers
        rcvd_pza=rcvd_pza+' '+trainjson[i]['request_text_edit_aware']
        got_piza=got_piza+1 #count number of people who recieved pizza
    else:
        #all text by non recievers
        not_rcvd_pza=not_rcvd_pza+' '+trainjson[i]['request_text_edit_aware']
        not_get_piza=not_get_piza+1

"""dictionary of all the words with their frequency"""
freq_rcvd , rcvd_words=frequency_count(rcvd_pza) #dictionary containing all words used by pizza recicvers
freq_not_rcvd , not_rcvd_words=frequency_count(not_rcvd_pza) #dictionary containing all words used by non-pizza recicvers
freq_total , total_words=frequency_count(rcvd_pza+not_rcvd_pza) #dictionary of all the words by all requesters

#-------------------------------------------------------------------------
#dictionary which tells about the probability of a word leading to pizza gain
prob_rcving={}
#dictionary which tells about the probability of a word leading to pizza losing
prob_not_rcving={}


#===========this is the naive-bayes part==============
for i in freq_total:
    if i in freq_rcvd:
        prob_rcving[i]=(freq_rcvd[i]+1.0)/(rcvd_words+len(freq_total))*1000
    else:
        prob_rcving[i]=(1.0)/(rcvd_words+len(freq_total))*1000
    if i in freq_not_rcvd:
        prob_not_rcving[i]=(freq_not_rcvd[i]+1.0)/(not_rcvd_words+len(freq_total))*1000
    else:
        prob_not_rcving[i]=(1.0)/(not_rcvd_words+len(freq_total))*1000

prob_rcv=(got_piza*1.0)/(got_piza+not_get_piza) #fraction of people recieved pizza
prob_not_rcv=(not_get_piza*1.0)/(got_piza+not_get_piza) #didn't recieve pizza


def predict(request):
    x,y=frequency_count(request);
    will_rcv=1;
    will_not_rcv=1;
    for i in x:
        if i in prob_rcving:
            will_rcv=will_rcv*pow(prob_rcving[i],x[i]);
        if i in prob_not_rcving :
            will_not_rcv=will_not_rcv*pow(prob_not_rcving[i],x[i])
        will_rcv=will_rcv*prob_rcv;
        will_not_rcv=will_not_rcv*prob_not_rcv;
        if will_rcv>will_not_rcv:
            #print("Will recieve a pizza")
            return 1;
        elif will_not_rcv>will_rcv:
            #print("Don't give him a pizza")
            return 0;
        else:
            print("I am confused")
x={};
y=0
for i in range(0,len(testjson)):
    x[testjson[i]['request_id']]=predict(testjson[i]['request_text_edit_aware'])
    y=y+x[testjson[i]['request_id']]
with open('prediction.csv','wb') as fo:
    #fieldnames=['request_id','requester_recieved_pizza']
    w=csv.writer(fo)
    for key,val in x.items():
        w.writerow([key,val])
