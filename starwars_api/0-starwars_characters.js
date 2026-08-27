#!/usr/bin/node

const process = require('process');
const request = require('request');

function GetMovieJsonContent(movieId) {
    return new Promise((resolve, reject) => {
        const url = `https://swapi-api.hbtn.io/api/films/${movieId}`;

        request(url, (error, response, body) => {
            if (error) {
                reject(error);
                return;
            }

            if (response.statusCode !== 200) {
                reject(new Error(`Response status: ${response.statusCode}`));
                return;
            }

            const movieContent = JSON.parse(body);
            resolve(movieContent);
        });
    });
}

function GetCharacter(characterUrl) {
    return new Promise((resolve, reject) => {
        request(characterUrl, (error, response, body) => {
            if (error) {
                reject(error);
                return;
            }

            if (response.statusCode !== 200) {
                reject(new Error(`Response status: ${response.statusCode}`));
                return;
            }

            const character = JSON.parse(body);
            resolve(character);
        });
    });
}

function GetCharactersWithUrlFrom(json) {
    const characterUrls = json.characters;

    const characterDatas = characterUrls.map((characterURL) => {
        return GetCharacter(characterURL);
    });

    return Promise.all(characterDatas);
}

function GetCharacterNames(characters) {
    const characterNames = [];

    characters.map((character) => {
        const characterName = character.name;
        characterNames.push(characterName);
    });

    return characterNames;
}

async function main() {
    const movieId = process.argv[2];

    try {
        const movieContent = await GetMovieJsonContent(movieId);
        const charactersJson = await GetCharactersWithUrlFrom(movieContent);
        const characterNames = GetCharacterNames(charactersJson);

        characterNames.map((characterName) => {
            console.log(characterName);
        });
    } catch (error) {
        console.error(error.message);
    }
}

main();

