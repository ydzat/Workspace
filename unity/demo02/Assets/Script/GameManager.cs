using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
public enum GameState{
    Ready = 0,
    Running = 1,
    Pause = 2,
    Gameover = 3,
}



public class GameManager : MonoBehaviour
{
    public GameObject pipelineObj;
    public float pipelinePos_x = 5;

    public float timer = 0;
    public float randomTime = 2;
    public float minRandomTime = 0.5f;
    public float maxRandomTime = 1.5f;

    public float max_y = 0.2f;
    public float min_y = -5;

    public Button startButton;
    public Button restartButton;

    public GameState gameState = GameState.Ready;


    public static GameManager _gameManager;
    public Rigidbody2D birdRigidbody;

    // Start is called before the first frame update
    void Start()
    {
        _gameManager = this;
        startButton.gameObject.SetActive(true);
        restartButton.gameObject.SetActive(false);

    }

    // Update is called once per frame
    void Update()
    {

        if(gameState != GameState.Running) return;

        timer += Time.deltaTime;
        if(timer >= randomTime){
            PipelineBorn();
        }
    }

    void PipelineBorn(){
        Vector3 pipelinePos = new Vector3(pipelinePos_x, Random.Range(min_y, max_y), pipelineObj.transform.position.z );
        Instantiate(pipelineObj, pipelinePos, pipelineObj.transform.rotation);
        randomTime = Random.Range(minRandomTime, maxRandomTime);
        timer = 0;
    }

    public void GameStart(){
        gameState = GameState.Running;
        startButton.gameObject.SetActive(false);
        restartButton.gameObject.SetActive(false);
        PipelineBorn();

        
        if(birdRigidbody != null){
            birdRigidbody.gravityScale = 1.2f;
        }
    }

    public void GameRestart()
    {
        gameState = GameState.Running;
        // not working
        SceneManager.LoadScene(0);
        GameStart();
    }

}
