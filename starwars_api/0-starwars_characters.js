#!/usr/bin/node

import process from 'process'

async function GetMovieJsonContent(movieId){
  const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;
  try {
    const response = await fetch(url);
    if (!response.ok) {
      throw new Error(`Response status: ${response.status}`);
    }

    const result = await response.json();
    return result
  } catch (error) {
    console.error(error.message);
  }
}
async function GetCharactersFromUrls(urlList){

}
async function GetCharactersWithUrlFrom(json){
    const characters_url = json["characters"]
    const characterPromises = characters_url.map(async (character_url)=>{
        try{
            const response = await fetch(character_url)
            if(!response.ok){
                throw new Error(`Response status: ${response.status}`);
            }
            const character = await response.json()
            return character
        }
        catch (error) {
            console.error(error.message);
        }
    })
    const characters = Promise.all(characterPromises)
    return characters
}

function GetCharacterNames(characters){
    const characterNames = []
    characters.map((character)=>{
        const characterName = character["name"]
        characterNames.push(characterName)
    })
    return characterNames
}

const movieId = process.argv[2]
const movieContent = await GetMovieJsonContent(movieId)
const characters_json = await GetCharactersWithUrlFrom(movieContent)
const characterNames = GetCharacterNames(characters_json)

characterNames.map((characterName)=>{
    console.log(characterName)
})

