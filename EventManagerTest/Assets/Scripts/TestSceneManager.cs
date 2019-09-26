using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Linq;
using System;
using UnityEngine.SceneManagement;
using System.Text;

public class TestSceneManager : MonoBehaviour
{
    public static TestSceneManager Ins = null;

    private GameObject cube;

    void Awake()
    {
        Ins = this;

        cube = transform.Find("Cube").gameObject;
    }

    void Start()
    {
        RegisterEvent();
        StartCoroutine(CoCheckBackBtn());
    }

    Stack<EVENT_TYPE> stack; //팝업창 관리

    //Back버튼 이벤트
    IEnumerator CoCheckBackBtn()
    {
        stack = new Stack<EVENT_TYPE>();
        while (true)
        {
            if (Input.GetKeyDown(KeyCode.Escape))   //ESC키를 눌렀을때
            {
                if (stack.Count > 0)
                {
                    Debug.Log(0);
                    switch (stack.Peek())
                    {
                        case EVENT_TYPE.OBJECT_ACTIVE:
                            EventManager.Ins.PostNotification(EVENT_TYPE.OBJECT_INACTIVE, this);
                            break;
                    }
                }
            }
            else if (Input.GetKeyDown(KeyCode.A))
            {
                Debug.Log(1);
                EventManager.Ins.PostNotification(EVENT_TYPE.OBJECT_ACTIVE, this);
            }
            yield return null;
        }
    }

    /// <summary>
    /// 외부에서 스택 제거
    /// </summary>
    public void PopStack()
    {
        //스택에 아무것도 없는 경우 그냥 지나가기
        if (stack.Count == 0)
            return;

        switch (stack.Peek())
        {
            case EVENT_TYPE.OBJECT_ACTIVE:
                stack.Pop();
                break;
        }
    }

    /// <summary>
    /// 외부에서 스택 전체제거
    /// </summary>
    public void StackAllPop()
    {
        while (stack.Count > 0)
        {
            stack.Pop();
        }
    }

    #region EVENT
    /// <summary>
    /// 이벤트를 등록합니다
    /// </summary>
    void RegisterEvent()
    {
        EventManager.Ins.AddListener(EVENT_TYPE.OBJECT_ACTIVE, OnEvent);
        EventManager.Ins.AddListener(EVENT_TYPE.OBJECT_INACTIVE, OnEvent);
    }

    public void StackPush(EVENT_TYPE e)
    {
        if (stack.Contains(e))
        {
            return;
        }
        stack.Push(e);
    }

    void OnEvent(EVENT_TYPE aEventType, Component Sender, params object[] aParam)
    {
        switch (aEventType)
        {
            case EVENT_TYPE.OBJECT_ACTIVE:
                cube.SetActive(true);
                stack.Push(EVENT_TYPE.OBJECT_ACTIVE);
                break;
            case EVENT_TYPE.OBJECT_INACTIVE:
                cube.SetActive(false);
                stack.Pop();
                break;
        }
    }
    #endregion
}
