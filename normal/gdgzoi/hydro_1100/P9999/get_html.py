# curl 'http://gdgzoi.com/showsource.php?id=732872' \
#   -H 'Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7' \
#   -H 'Accept-Language: zh-CN,zh;q=0.9,en;q=0.8,ru;q=0.7,zh-TW;q=0.6' \
#   -H 'Cache-Control: max-age=0' \
#   -H 'Connection: keep-alive' \
#   -H 'Cookie: expanded_dir_list=%3A%3Ahome%3Ajudge%3Asrc%3Aweb%3Agzezadmin; fm_current_root=%2Fhome%2Fjudge%2Fsrc%2Fweb%2F; loggedon=d41d8cd98f00b204e9800998ecf8427e; ckCsrfToken=BMM8I3zwKODHbcYJt8gk63lSftm9nBeTKk0qW36V; lastlang=undefined; PHPSESSID=reascfmq7sfeb807f5objalt74' \
#   -H 'Referer: http://gdgzoi.com/status.php?&problem_id=3444&jresult=4&top=732918&prevtop=741586' \
#   -H 'Upgrade-Insecure-Requests: 1' \
#   -H 'User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Safari/537.36' \
#   --insecure

import requests

cookies = {
    'expanded_dir_list': '%3A%3Ahome%3Ajudge%3Asrc%3Aweb%3Agzezadmin',
    'fm_current_root': '%2Fhome%2Fjudge%2Fsrc%2Fweb%2F',
    'loggedon': 'd41d8cd98f00b204e9800998ecf8427e',
    'ckCsrfToken': 'BMM8I3zwKODHbcYJt8gk63lSftm9nBeTKk0qW36V',
    'lastlang': 'undefined',
    'PHPSESSID': 'reascfmq7sfeb807f5objalt74',
}

headers = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.7',
    'Accept-Language': 'zh-CN,zh;q=0.9,en;q=0.8,ru;q=0.7,zh-TW;q=0.6',
    'Cache-Control': 'max-age=0',
    'Connection': 'keep-alive',
    # Requests sorts cookies= alphabetically
    # 'Cookie': 'expanded_dir_list=%3A%3Ahome%3Ajudge%3Asrc%3Aweb%3Agzezadmin; fm_current_root=%2Fhome%2Fjudge%2Fsrc%2Fweb%2F; loggedon=d41d8cd98f00b204e9800998ecf8427e; ckCsrfToken=BMM8I3zwKODHbcYJt8gk63lSftm9nBeTKk0qW36V; lastlang=undefined; PHPSESSID=reascfmq7sfeb807f5objalt74',
    'Referer': 'http://gdgzoi.com/status.php?&problem_id=3444&jresult=4&top=732918&prevtop=741586',
    'Upgrade-Insecure-Requests': '1',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/124.0.0.0 Safari/537.36',
}

params = {
    'id': '732872',
}

response = requests.get('http://gdgzoi.com/showsource.php', params=params, cookies=cookies, headers=headers, verify=False)

with open('example.html', 'w') as f:
    f.write(response.text)