# C Calculator Project

GitHub Actions, GHCR(GitHub Container Registry), Windows self-hosted runner, Docker Compose를 이용하여 **C 언어 계산기 프로젝트의 CI/CD 자동화**를 구현한 실습 프로젝트입니다.

본 프로젝트는 단순한 계산기 프로그램 구현을 넘어, 다음과 같은 DevOps 자동화 흐름을 실제로 검증하는 것을 목표로 합니다.

- C 소스코드 빌드
- 테스트 자동 수행
- Docker 이미지 생성
- GHCR 이미지 업로드
- Windows self-hosted runner를 통한 자동 배포
- Docker Compose 기반 컨테이너 실행 및 검증

---

## 1. 프로젝트 개요

이 프로젝트는 C 언어로 작성한 사칙연산 계산기 프로그램을 대상으로, GitHub 저장소에 코드가 push되면 자동으로 다음 작업이 수행되도록 구성하였습니다.

1. GitHub Actions에서 소스코드 체크아웃
2. Ubuntu 환경에서 프로젝트 빌드
3. 테스트 코드 실행
4. Docker 이미지 빌드
5. GHCR에 이미지 push
6. Windows self-hosted runner에서 최신 이미지 pull
7. Docker Compose로 컨테이너 재배포
8. 배포 상태 및 로그 확인

즉, 본 실습은 **C 언어 + GitHub Actions + Docker + GHCR + self-hosted runner**를 연계한 입문형 CI/CD 구축 실습입니다.

---

## 2. 실습 목표

본 실습의 목표는 다음과 같습니다.

- C 언어 프로젝트를 모듈화하여 구성할 수 있다.
- `Makefile`을 이용하여 빌드/테스트/정리 작업을 자동화할 수 있다.
- GitHub Actions workflow를 작성하여 CI 파이프라인을 구성할 수 있다.
- Dockerfile을 이용하여 실행 이미지를 만들 수 있다.
- GHCR를 이용하여 Docker 이미지를 저장·배포할 수 있다.
- Windows self-hosted runner를 이용하여 운영 환경에 자동 배포할 수 있다.
- Docker Compose로 컨테이너 실행 및 상태 확인을 수행할 수 있다.

---

## 3. 프로젝트 기능

본 프로젝트는 다음 기능을 포함합니다.

- 두 정수 입력
- 덧셈
- 뺄셈
- 곱셈
- 나눗셈
- 계산 결과 출력
- 테스트 코드 실행
- CI/CD 자동화

---

## 4. 개발 및 실행 환경

### 개발 환경
- Windows 11
- VS Code
- Git
- GitHub
- PowerShell 7 (`pwsh`)
- GCC
- Make

### CI 환경
- GitHub Actions
- `ubuntu-latest`

### 배포 환경
- Windows self-hosted runner
- Docker Desktop
- Docker Compose
- GHCR

---

## 5. 폴더 구조

```text
c-calculator-project/
├─ .github/
│  └─ workflows/
│     └─ c-ci.yml
├─ include/
│  └─ calc.h
├─ src/
│  ├─ add.c
│  ├─ div.c
│  ├─ main.c
│  ├─ mul.c
│  ├─ print_result.c
│  └─ sub.c
├─ tests/
│  └─ test_calc.c
├─ .gitignore
├─ docker-compose.yml
├─ Dockerfile
├─ Makefile
└─ README.md

