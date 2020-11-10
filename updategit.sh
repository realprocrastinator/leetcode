#!/bin/bash

ssh-agent -s
ssh-add ~/.ssh/git_hub_id_rsa

git config --global user.name 'realprocrastinator'
git config --global user.email '1106364305@qq.com'

git pull --verbose

git add -A

git commit  -m "new update for the probsets"

GITHUB_AUTH=$(echo -n "${GITHUB_ACTOR}:${GITHUB_TOKEN}" | base64)
GITHUB_REF=./refs/heads/main

git -c http.extraheader="AUTHORIZATION: basic ${GITHUB_AUTH}" push -u origin "HEAD:${GITHUB_REF##*/}"
