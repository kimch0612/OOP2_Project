# Yahtzee Dice Manual

## 게임을 플레이하기 위한 최소사양
| Type | Content |
|:---|:---|
| OS | Windows 10 |
| Architecture | x86 |
| Resolution | 1280x720 |
| RAM | 4GB |

위 사양보다 낮은 경우에서의 작동은 보장하지 않습니다.

## UI 설명
![Screenshot_20231030_132900_Samsung Notes](https://github.com/kimch0612/OOP2_Project/assets/10193967/bd66412a-ae1d-4b7e-a7a6-b9524cb93f88)
- welcome label: 게임을 실행했을 때 타이틀을 표시하는 라벨입니다.
- button section: 게임과 관련된 버튼이 존재합니다.
  - start: 게임을 시작합니다.
  - manual: 게임의 매뉴얼을 봅니다.
  - credits: 게임에서 사용한 open source나 copyleft 항목들을 볼 수 있습니다.
  - exit: 게임을 종료합니다.

![Screenshot_20231030_132742_Samsung Notes](https://github.com/kimch0612/OOP2_Project/assets/10193967/68a82c83-c23f-42dd-b83a-34022a95edd8)
- credit title: Credit Window의 Title text를 저장하고 띄우는 label입니다.
- credit item: Credit Window의 상호작용 가능한 항목들입니다.
- button section: Credit과 관련된 버튼이 존재합니다.
  - back: 뒤로 돌아갑니다.

![Screenshot_20231030_132813_Samsung Notes](https://github.com/kimch0612/OOP2_Project/assets/10193967/1eb38580-7492-4e5a-a727-cebd0dea2d7a)
- current user label: 현재 플레이 중인 플레이어의 이름이 뜹니다.
- dice section: 주사위와 관련된 항목들이 존재합니다.
  - reroll button: 주사위를 재생성합니다.
  - hold button: 주사위를 재생성할 때 hold된 주사위는 재생성되지 않습니다.
- timer&turn section: 타이머와 현재 남은 턴을 보여줍니다.
- digit dice section: 1부터 6, bonus가 존재하는 score section입니다.
- c-y dice section: Choice부터 Yahztee가 존재하는 score section입니다.
- total score section: 현재 각각의 User가 흭득한 총 점수가 표시됩니다.

![Screenshot_20231030_132841_Samsung Notes](https://github.com/kimch0612/OOP2_Project/assets/10193967/52a63ca9-6c77-4b5c-9bf1-73cb22930702)
- game-set label: "Game Set!" 텍스트를 저장하고 표시합니다.
- winner label: total score를 비교해 점수가 더 높은 사람의 이름을 띄웁니다.
- button section: Winner Window와 관련된 버튼이 존재합니다.
  - restart: 게임을 처음부터 다시 시작합니다.
  - exit: 게임을 종료합니다.

## 룰 설명
- [이곳을 클릭해주세요](./rules.md)
