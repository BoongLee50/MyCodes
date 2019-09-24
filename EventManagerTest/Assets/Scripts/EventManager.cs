using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public enum EVENT_TYPE
{
    LOADING_ACTIVE,  
    LOADING_INACTIVE,
}
public class EventManager : MonoBehaviour
{
    private static EventManager _EventManager;
    public static EventManager Ins
    {
        get
        {
            if (_EventManager == null)
            {
                _EventManager = FindObjectOfType<EventManager>();

                if (_EventManager == null)
                {
                    GameObject obj = new GameObject("@EventManager");
                    _EventManager = obj.AddComponent<EventManager>();
                }
            }
            return _EventManager;
        }
    }

    public delegate void OnEvent(EVENT_TYPE aEventType, Component Sender, params object[] aParam);

    //이벤트 리스너 오브젝트의 배열
    private Dictionary<EVENT_TYPE, List<OnEvent>> listeners = new Dictionary<EVENT_TYPE, List<OnEvent>>();

    /// <summary>
    /// 리스너 배열에 지정된 리스너 오브젝트를 추가하기 위한 함수
    /// </summary>
    /// <param name="aEventType">수신할 이벤트</param>
    /// <param name="aListener">이벤트를 수신할 오브젝트</param>
    public void AddListener(EVENT_TYPE aEventType, OnEvent aListener)
    {
        //이 이벤트를 수신할 리스너의 리스트
        List<OnEvent> listenList = null;

        //이벤트 형식 키가 존재하는지 검사 존재하면 리스트에 추가합니다
        if (listeners.TryGetValue(aEventType, out listenList))
        {
            listenList.Add(aListener);
            return;
        }
        else
        {
            //아니면 새로운 리스트를 생성한다
            listenList = new List<OnEvent>();
            listenList.Add(aListener);
        }

        //내부의 리스너 리스트에 추가한다
        listeners.Add(aEventType, listenList);
    }

    /// <summary>
    /// 이벤트를 리스너에게 전달하기 위한 함수
    /// 모든 리스너에게 이벤트를 알립니다..
    /// </summary>
    /// <param name="aEventType">발생한 이벤트</param>
    /// <param name="aSender">이벤트를 포스팅한 컴포넌트</param>
    /// <param name="Param">선택 가능한 파라메터</param>
    public void PostNotification(EVENT_TYPE aEventType, Component aSender, params object[] aParam)
    {
        //이 이벤트를 수신하는 리스너들의 리스트
        List<OnEvent> listenList = null;

        //이벤트를 수신하는 리스너들이 없으면 종료
        if (!listeners.TryGetValue(aEventType, out listenList))
            return;

        //존재한다면 발생한 이벤트를 리스너한테 알려준다
        for (int i = 0; i < listenList.Count; i++)
        {
            //오브젝트가 존재한다면 델리게이트를 통해 메세지를 보냅니다..
            if (!listenList[i].Equals(null))
            {
                listenList[i](aEventType, aSender, aParam);
            }
        }
    }

    /// <summary>
    /// 대상이벤트의 리스너 항목을 리스너 관리 딕셔너리에서 제거합니다
    /// </summary>
    /// <param name="aEventType"></param>
    public void RemoveEvent(EVENT_TYPE aEventType)
    {
        listeners.Remove(aEventType);
    }

    /// <summary>
    /// 이벤트 리스너 딕셔너리에 쓸모없는 항목을 제거합니다
    /// </summary>
    public void RemoveRedundancies()
    {
        //새 딕셔너리 생성
        Dictionary<EVENT_TYPE, List<OnEvent>> tmpListeners = new Dictionary<EVENT_TYPE, List<OnEvent>>();

        foreach (var item in listeners)
        {
            //만약 이부분에서 오류나면 역순회로 돌려볼것
            for (int i = 0; i < item.Value.Count; i++)
            {
                if (item.Value[i].Equals(null))
                    item.Value.RemoveAt(i);
            }

            //알림을 받기 위한 항목들만 리스트에 남으면 이 항목들을 임시 딕셔너리에 넣는다
            if (item.Value.Count > 0)
                tmpListeners.Add(item.Key, item.Value);
        }

        //새로 최적화된 딕셔너리로 교체한다
        listeners = tmpListeners;
    }
}
