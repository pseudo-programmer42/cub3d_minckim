# cub3d_minckim
## 점수 | Score
- 115/100
### 보너스 | Bonus
1. 벽 충돌 | Wall collision
2. 바닥/벽 텍스처 | Floor and/or ceilling texture
3. HUD | An HUD
4. 위아래 보기 | Abillity to look up and down
5. 점프/웅크리기 | Jump or crouch
6. 거리에 따른 그림자 효과 | A distance related shadow effect
7. 생명력 바 | Life bar
8. 미로에 더 많은 아이템 | More items in the maze
9. 오브젝트와 충돌 | Object collisions
10. 오브젝트/함정으로 점수나 생명력 잃거나 얻기 | Earning points and/or losing life by picking up objects/traps
11. 열기/닫기 되는 문 | Doors which can open and close
12. 비밀의 문 | Secret doors
13. 총 쏘기 에니메이션 또는 스프라이트 에니메이션 | Animations of a gun shot or animated sprite
14. 마우스로 화면 회전 | Roatae the point of view with the mouse
## 실행하기
- 필수파트

      $ make
      $ ./cub3D map2.cub

- 보너스파트

      $ make bonus
      $ ./cub3D map_bonus.cub

- 조작
      - 이동: w a s d

      - 화면회전: 화살표 좌우
- 보너스 조작
      - 이동: w a s d

      - 화면회전: 화살표 + 마우스

      - 점프: space

      - 앉기: c

보너스파트와 필수파트의 실행파일의 이름이 같음에 주의(고쳐야 되는데 너무 귀찮은것..ㅠㅠ)
### 기타
- 필수파트부터 3차원 공간상의 삼각형을 출력하도록 해서, 해상도를 높일 경우 매우 느립니다.
- NSEW가 각각 맨 처음에 바라보는 방향인 것을 평가가 다 끝나고 알았습니다...NSEW에 관계 없이 모두 동쪽을 바라보고 초기화됩니다
- 화면 해상도를 받는 것은 코어그래픽 헤더를 이용했습니다.
- DDA알고리즘 대신 자체 고안한 알고리즘을 사용했습니다.
  1. 픽셀마다 해당 픽셀의 색을 갖게 하는 거리를 저장
  2. 면마다 화면에서 차지하는 픽셀을 설정하고, 설정된 범위 내에서만 계산
  3. 면의 법선벡터와 시야를 고려하여 출력될 가능성이 없는 면은 계산에서 제외함
  4. 면과 시점 사이의 최소 거리가 픽셀에 저장된 거리 값보다 먼 경우 계산에서 제외함
  5. 출력할 요소를 연결리스트로 구성했고, 출력에 성공할 때마다 해당 노드를 맨 앞으로 가져옴. 4번 알고리즘의 성능을 극대화 함.
  6. 시간과 건강을 갈아 넣음
