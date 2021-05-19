# [출처](https://velog.io/@hgmhc/CC-STL-%EB%AA%A8%EC%9D%8C%EC%A7%91) 및 기본 내용

● f, l은 앞 주소와 뒷 주소를 나타내고, 여러 개면 번호를 붙였습니다. <br>
● func은 호출할 함수를 나타냅니다. <br>





# 1. 입출력

<h3> 속도 개선 </h3>
● 입출력:<br>
ios::sync_with_stdio(0); cin.tie(0); (사용 시 c의 입출력은 더 이상 사용 불가)<br>
● push_back:<br> 
emplace_back 으로 대신하기 (중복을 허용하지 않는 set, map 등의 자료구조는 개선된다고 보장할 수는 없음.)

<h3> 문자열 </h3>
● 공백까지 통째로 한 줄 입력:<br>
getline(cin,s)<br>
● 숫자 하나 입력:<br>
scanf("%.1d",&a)


<h3> 서식 </h3>
● 소수점 자릿수 조정:<br>
1. printf("%.6f",a) <br>
2. cout << fixed 로 소수점 고정 후 cout.precision(6)로 정밀도 조정<br>
● 부호 표시:<br>
cout << showpos <br>
● 진수 변환:<br>
cout << dec, &nbsp  cout << oct, &nbsp cout << hex <br>
+) 0또는 0x 붙이고 싶다면, cout << showbase



# 2. 순열 생성
● 다음 순열: <br>
next_permutation(f,l)


# 3. 이진탐색 기반 함수
자료구조마다 제공되는 find 함수도 이진탐색 기반이다. <br><br>
● 존재성(bool): <br>
binary_search(f,l,x) <br>
● x보다 큰 최소 원소 위치(iterator): <br>
lower_bound(f,l,x) <br>
● x보다 작은 최소 원소 위치(iterator): <br>
upper_bound(f,l,x) <br>
● x가 연속된 구간(pair): <br>
equal_range(f,l,x) <br>


# 4. 배열 / 벡터의 조작
● 정렬: <br>
sort(f,l) <br>
● 역순정렬: <br>
sort(f,l,greater<int>()) <br>
sort(v.rbegin(),v.rend()) (배열x 벡터만 가능) <br>
● 뒤집기: <br>
reverse(f,l) <br>
● 원소 돌리기: <br>
rotate(f,l) <br>
● 최대 원소: <br>
max_element(f,l) <br>
● 두 구간이 같은지: <br>
equal(f1,l1,f2) <br>
● 순서 보존하여 병합(3 <- 1 + 2): <br>
merge(f1,l1,f2,l2,f3) <br>
● 구간 바꾸기: <br>
swap_ranges(f1,l1,f2) <br>
● 구간 복붙하기(2에 붙여넣음): <br>
copy(f1,l1,f2) <br>
● 채우기 (0 혹은 1 처럼 단문자 같은 1byte 짜리, 속도빠름): <br>
memset(f,x,size) <br>
● 채우기 (아무거나 다 가능): <br>
fill(f,l,x) <br>
● 바꿔치기: <br>
replace(f,l,x,y) <br>
replace_if(f,l,func,y) <br>
● 지우기: <br>
v.erase(i) <br>
v.erase(f,l) <br>
remove(f,l,x,y) <br>
remove_if(f,l,func,y) <br>
● 묶어버리기(= 압축해버리기) : <br>
unique(f,l) <br>
● 섞어버리기: <br>
random_shuffle(f,l) <br>

  
# 5. 수학
log(x) <br>
abs(x) <br>
gcd(x) <br>
lcm(x) <br>
  
# 6. 기본적인 함수
max(a,b) <br>
swap(a,b) <br>

  
# 7. 에러 잡기
assert(조건문) <br>
  

  
