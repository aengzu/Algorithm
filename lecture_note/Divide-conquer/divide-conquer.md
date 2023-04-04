### Divide-conquer

# Divide(분할) + Conquer(정복) 
일반적으로 주어진 문제를 다음과 같은 방식으로 해결하는 알고리즘을 말함

1. 주어진 문제를 작은 단위(subproblem) 으로 쪼갠다.
2. 1번에서 나눈 subproblem 을 recursively 하게 해결한다.
3. 2번에서 푼 subproblem 들을 답을 적절하게 조합(combine, merge) 해서 본 문제의 답을 제시한다.


### Merge sort

Array A 를 merge sort 하시오 : 1. A를 Base case( array size 가 1이 될 때까지) 쪼갠다 2. subproblem 의 답을 머지하면서 원래 input 에 해당하는 문제를 해결한다 ( Bottom-up soution)

### Master Theorem

1. size 가 n/b 인 a개의 subproblem 으로 나눈다 
2. 각각의 subproblem 을 해결한뒤 O($n^d$) 시간을 사용하여 subproblem 의 답을 merge 한다.

이 때 T(n) 을 Time Complexity 라 할 때 다음과 같은 recurrence relation 을 얻을 수 있다.
T(n) = aT(n/b) + O($n^d$)

Master Theorem 을 이용하면 다음과 같은 일반해가 나온다.

T(n) =  O($n^d$) if d> $log_b{a}$ 

T(n) =  O($n^dlog{n}$) if d= $log_b{a}$ 

T(n) =  O($log_b{a}$) if d < $log_b{a}$ 
       
       
