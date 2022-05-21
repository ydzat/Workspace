using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class 实列化敌人 : MonoBehaviour
{
    public DiRen  敌人;
    public Transform 玩家;
    public Transform[] 实列位置;
    float Timer = 0;

    // Start is called before the first frame update
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
            Timer += Time.deltaTime;
            if (Timer > 2)
            {
                DiRen 小敌人= Instantiate(敌人, 实列位置[Random.Range(0, 实列位置.Length)]);
                小敌人.goal = 玩家;
                Timer = 0;
                Debug.Log("实列化敌人");
            }
    }

}
