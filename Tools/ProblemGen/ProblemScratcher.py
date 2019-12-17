# -*- coding: UTF-8 -*-
#!/usr/bin/python3

import re
import json
import requests
import html2text
from bs4 import BeautifulSoup

headers = {
  "Host": "leetcode-cn.com",
  "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64; rv:71.0) Gecko/20100101 Firefox/71.0",
  "Accept": "*/*",
  "Accept-Language": "zh-CN,zh;q=0.8,zh-TW;q=0.7,zh-HK;q=0.5,en-US;q=0.3,en;q=0.2",
  "Accept-Encoding": "gzip, deflate, br",
  "Referer": "https://leetcode-cn.com/problems/minimum-falling-path-sum-ii/description/",
  "content-type": "application/json",
  "X-CSRFToken": "kuAVz8NDzTF9JRTVZwGbmipeA1NAdkghCdoO9iXCX0YP65cSlduf1Q8w8A2WbirJ",
  "Origin": "https://leetcode-cn.com",
  "Content-Length": "1150",
  "Connection": "keep-alive",
  "Cookie": "csrftoken=kuAVz8NDzTF9JRTVZwGbmipeA1NAdkghCdoO9iXCX0YP65cSlduf1Q8w8A2WbirJ; _uab_collina=157198034557491429946795",
  "TE": "Trailers",
}

payload = {
  "operationName":"questionData",
  "variables":{"titleSlug":""},
  "query": "query questionData($titleSlug: String!) {  question(titleSlug: $titleSlug) {    questionId    questionFrontendId    boundTopicId    title    titleSlug    content    translatedTitle    translatedContent    isPaidOnly    difficulty    likes    dislikes    isLiked    similarQuestions    contributors {      username      profileUrl      avatarUrl      __typename    }    langToValidPlayground    topicTags {      name      slug      translatedName      __typename    }    companyTagStats    codeSnippets {      lang      langSlug      code      __typename    }    stats    hints    solution {      id      canSeeDetail      __typename    }    status    sampleTestCase    metaData    judgerAvailable    judgeType    mysqlSchemas    enableRunCode    envInfo    book {      id      bookName      pressName      description      bookImgUrl      pressImgUrl      productUrl      __typename    }    isSubscribed    __typename  }}"
}

filename=""

def get(prob):
  problemUrl = "https://leetcode-cn.com/problems/"+prob+"/"
  response = requests.get(problemUrl)
  #print(response.headers)

  url = "https://leetcode-cn.com/graphql/"
  headers["Refer"] = "https://leetcode-cn.com/problems/" + prob + "/description/"
  headers["X-CSRFToken"] : "kuAVz8NDzTF9JRTVZwGbmipeA1NAdkghCdoO9iXCX0YP65cSlduf1Q8w8A2WbirJ"
  headers["Cookie"]: "csrftoken=kuAVz8NDzTF9JRTVZwGbmipeA1NAdkghCdoO9iXCX0YP65cSlduf1Q8w8A2WbirJ; _uab_collina=157198034557491429946795"

  payload["variables"]["titleSlug"] = prob

  response = requests.post(url,headers=headers,data=json.dumps(payload))
  # print(response.text)  #返回响应的内容以unicode表示

  dictInfo = json.loads(response.text)
  q = dictInfo["data"]["question"]
  save_problem(q)


def save_problem(q):
  pc = parsedContent(q)
  with open(filename,'a+',encoding="utf-8")as f:
    f.write(pc)

def parsedContent(q):
  pc = "\n# " + q["questionFrontendId"] +"."+ q["translatedTitle"]+"\n"
  pc += "[" +q["questionFrontendId"] +"."+ q["translatedTitle"] +"](" + "https://leetcode-cn.com/problems/" + q["title"].replace(' ','-')  +")\n\n"
  h = html2text.HTML2Text()
  pc += h.handle(q["translatedContent"])
  p = pc.find("**示例 1：**")
  if p != -1:
    pc =  pc[:p-1] + "## 样例输入与样例输出 Sample Input and Sample Output\n" + pc[p:]
  p = pc.find("**提示：**")
  if p != -1:
    pc =  pc[:p-1] + "## 提示 Hint\n" + pc[p:]
  pc += "\n## 代码\n"
  return pc

def main():
  global filename
  filename = u"weekly-contest-167"+ ".md"
  urlList = [
    "convert-binary-number-in-a-linked-list-to-integer",
    "sequential-digits",
    "maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold",
    "shortest-path-in-a-grid-with-obstacles-elimination",
  ]
  for prob in urlList:
    get(prob)

if __name__ == '__main__':
  main()