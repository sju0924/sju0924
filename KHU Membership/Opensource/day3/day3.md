# react-notion-x
오랜만에 제로보드 얘기를 들었다.<br>
- React+Notion+TypeScript
    - 글을 마음대로 쓰면서 사이트를 만들자!

* Notion: 팀에서 사용하기 적합한 노트 서비스
* 그의 경쟁자들: 에버노트 등. 
    * but 노션은 __`이쁘다`__

# react-notion-x 개발환경 구축

* npm-run-all: css,clean,s, html 모두 run
* preinstall, postinstall: npm install 명령이 들어왔을때 수행

# lerna

# Next js
* config 없음
* __Hybrid SSG& SSR__
    * SSG(Static site generation): HTML을 빌드 타임에 각 페이지를 생성. 빠른 처리 가능
    * express 이용
    * SSR: 요청이 올 때마다 HTML 생성