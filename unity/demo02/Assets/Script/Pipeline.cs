using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pipeline : MonoBehaviour
{
    public float speed = 2;
    public float x_limit = 3.5f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

        if(GameManager._gameManager.gameState != GameState.Running) return;

        this.gameObject.transform.position += new Vector3(1,0,0) * speed * Time.deltaTime;
        if(this.gameObject.transform.position.x <= - x_limit){
            Destroy(this.gameObject);
        }
    }
}
