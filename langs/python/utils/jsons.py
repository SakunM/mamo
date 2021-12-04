# coding: utf-8
import json
path = "a:/pj/sc/lib/dfs/jsons/std.json"

dict = ''
with open(path, encoding="utf-8", mode='r') as f:
  dict = f.read()
# topic, news, articles, ranking, docs = (ans["topic"], ans["news"], ans["articles"], ans["rankings"], ans["docs"])
print(type(dict))
print(dict)