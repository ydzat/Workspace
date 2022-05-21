using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class DiRen: MonoBehaviour
{
    public Transform goal;
    private NavMeshAgent agent;
    public int 血点;
    
    private Renderer 渲染器;
    private Color 颜色;
    private int 红;
    // Start is called before the first frame update
    void Start()
    {
       颜色 = new Color(255, 255, 0);
       渲染器 = GetComponent<Renderer>();
        agent = GetComponent<NavMeshAgent>();
        agent.destination = goal.position;
        红 = 255;
        
    }

    // Update is called once per frame
    void Update()
    {
        agent.destination = goal.position;
        
        

        if (血点 < 1)
        {
           Destroy(this.gameObject);
        }
    }

  
    private void OnCollisionEnter(Collision collision)
    {
        if ((Mathf.Abs(collision.relativeVelocity.y )> 2) && collision.collider.gameObject.tag == "Player")
        {
            红 = 红 - 125;
            Debug.Log(红);
            
            血点--;
            颜色 = new Color(红, 255, 0);
            渲染器.material.SetColor("_Color", 颜色);
        }
    }

}

       