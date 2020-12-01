import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-toc',
  templateUrl: './toc.page.html',
  styleUrls: ['./toc.page.scss'],
})
export class TocPage implements OnInit {
  public chapters = [
    {
      title: "Chapter 1 | The Beginning",
      url: '/chapter1'
    },
    {
      title: "Chapter 2 | Wilbur",
      url: '/chapter2'
    },
    {
      title: "Chapter 3 | Escape",
      url: '/chapter3'
    },
    {
      title: "Chapter 4 | Loneliness",
      url: '/chapter4'
    },
    {
      title: "Chapter 5 | Charlotte",
      url: '/chapter5' 
    }
  ];
  constructor() { }

  ngOnInit() {
  }

}
